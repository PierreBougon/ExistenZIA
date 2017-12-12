# [AModule]
[AModule] is the base abstract module for every modules, you shall never inherit directly from it (you will receive a compiler error) but rather inherit from its subclasses :
* [AHTTPModule]
* [ASharedModule]
* [AProtectedModule]

**Warning**, [AModule] has a handle to the .dll or the .so that **needs** to be set, this handle is automatically closed when the [AModule] is destroyed.

## [AHTTPModule]
[AHTTPModule] is a processing unit that uses a [Task] and either produces a [Response], provide data for further processing for next modules or process data passed by previous modules. If your module does neither of these, it may be going through an existential crisis...

### [DataStore]
To be able to pass data, each [AHTTPModule] has a [DataStore] that accepts the following basic types:
* char
* int
* float
* long
* double
* std::string

Inside a module, the [DataStore] works like a simple map with string keys. Getting data is as simple as :
```cpp
if (dataStore.hasData("someKey"))
  outDouble = dataStore.getData<double>("someKey");
```

While adding data is easly done like this :
```cpp
  dataStore.addData<std::string>("someOtherKey", "someValue");
```


### The Process Method
The method `Step process(ATask &task)` that the subclass must implement is where the process logic shall be coded. The following code snippet shows a [basic example] of a HTTPModule implementation:

```cpp
int xzia::BasicModule::do_some_operation(const xzia::Message &message, int multiplyBy)
{
    return (std::stoi(message.body) * multiplyBy);
}

xzia::Step xzia::BasicModule::process(xzia::ATask &task)
{
    int multiplyBy = 100;

    if (dataStore.hasData("multiply_by")) // 1
    {
        multiplyBy = dataStore.getData<int>("multiply_by"); // 2
    }

    int value_to_pass = 0;
    if (task.getRequest().hasBody()) // 3
    {
        value_to_pass = do_some_operation(task.getRequest(), multiplyBy); // 4
        task.getNextModule("Processor").dataStore.addData<int>("value", value_to_pass); // 5
    }

    std::unique_ptr<AHTTPModule> encryptor = moduleManager.getHTTPModule("Encryptor"); // 6
    if (value_to_pass == 400) {
        (*encryptor).dataStore.addData<std::string>("mode", "sha1");
        task.pushModuleBack(encryptor); // 7
    } else {
        (*encryptor).dataStore.addData<std::string>("mode", "md5");
        task.pushModuleNext(encryptor); // 8
    }

    DataStore dataLog;
    dataLog.addData("log", "something to log"); // 9
    moduleManager.getSharedModule("logger").process(dataLog); // 10

    return xzia::Step::Continue; // last
}
```

Let's check the data processing manipulation :
```cpp
    int multiplyBy = 100;

    if (dataStore.hasData("multiply_by")) // 1
    {
        multiplyBy = dataStore.getData<int>("multiply_by"); // 2
    }

    int value_to_pass = 0;
    if (task.getRequest().hasBody()) // 3
    {
        value_to_pass = do_some_operation(task.getRequest(), multiplyBy); // 4
        task.getNextModule("Processor").dataStore.addData<int>("value", value_to_pass); // 5
    }
```
1. Checking if some modules passed data to our BasicModule dataStore through the key "multiply_by"
2. Getting the actual data
3. Checking if the request has a body
4. Executing the operation method that take our request, and process it
5. Pushing the value into the next module called "Processor" dataStore.
last. Returning the [Step] Continue to tell the task to proceed to the next module in its executionList

### Modifying the [Task]'s execution list
Each module can modify the [Task]'s execution list, to do so, you must use the [ModuleManager], that is accessible to each [AHTTPModule], to create new modules. 
The following code snippet shows how to add a module to a [Task]'s execution list:
```cpp
    std::unique_ptr<AHTTPModule> encryptor = moduleManager.getHTTPModule("Encryptor"); // 6
    if (value_to_pass == 400) {
        encryptor->dataStore.addData<std::string>("mode", "sha1");
        task.pushModuleBack(encryptor); // 7
    } else {
        encryptor->dataStore.addData<std::string>("mode", "md5");
        task.pushModuleNext(encryptor); // 8
    }
```
6. Creating a new module from the module manager
7. Adding a new module at the end of the task list
8. Adding a new module right after the current module

## Shared Modules
While [AHTTPModule] is sufficient for processing request, you may want to have modules that are callable and accessible to all modules at any time (ie: a logging module).

### [ASharedModule]
This class inherits directly form [AModule] and dispose of an internal mutex to block critical part of the shared module's process method. We this module you can choose precisely each part of the process method you want to protect. 

Here's an example of how a [basic logger]'s process method could be implemented :
```cpp
xzia::Step xzia::BasicLogger::process(xzia::DataStore &dataStore) 
{
    mutex.lock();
    if (dataStore.hasData("log")) {
        std::string toLog = dataStore.getData<std::string>("log");
        std::cout << "BASIC LOG: " << toLog << std::endl;
    }
    mutex.unlock();
    return Step::Continue;
}
```
As you can see, it only takes a [DataStore] as a parameter, we believe a shared module shall __never__ need to access __nor__ modify a [Task]. 

And how to call it from any other modules :
```cpp
    DataStore dataLog; 
    dataLog.addData("log", "something to log"); // 9 
    moduleManager.getSharedModule("logger").process(dataLog); // 10
```
9. Creating a new dataStore, adding data to it
10. Getting a shared module and passing a DataStore to it

This [ASharedModule] exists for performance concerns, if you have heavy processing shared modules, you might want to protect only the small critical parts, thus gaining some precious milliseconds. 
But, you're probably thinking that having to use a mutex for such a trivial logger might be painful and time wasting. Don't worry, we think that way and that's why we provide you with a wonderful protected class : [AProtectedModule] !

### [AProtectedModule]
This class inherits from [ASharedModule], but instead of implementing the `process` method, the subclass shall implement the private `safeProcess` method, this method will be called by the [AProtectedModule]'s implemented process method.
```cpp
xzia::Step xzia::AProtectedModule::process(xzia::DataStore &dataStore)
{
    Step ret;

    mutex.lock();
    ret = safeProcess(dataStore);
    mutex.unlock();
    return ret;
}
```

When inheriting from [AProtectedModule], the previous logger implementation becomes :
```cpp
xzia::Step xzia::BasicLogger::safeProcess(xzia::DataStore &dataStore) 
{
    if (dataStore.hasData("log")) {
        std::string toLog = dataStore.getData<std::string>("log");
        std::cout << "BASIC LOG: " << toLog << std::endl;
    }
    return Step::Continue;
}
```

See? We made it simple for you :)

# [ModuleManager]
A [ModuleManager] shall the class responsible for storing all the modules of the HTTP server. It shall produce copies of [AHTTPModules]
and provide references to shared ones.

It also responsible for the creation of the [Task]'s execution list model that is copied through each [Task].

The [ModuleManager] is notified to reload all the modules through its `void reload()` method.

For any information on how to name modules and how to create a task list model, please refer to the [config.json] file provided as an example and read the documentation of the [Loader] package.

[Loader]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/loader
[config.json]: https://github.com/PierreBougon/ExistenZIA/blob/master/Examples/config.json
[AModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AModule.hpp
[AHTTPModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AHTTPModule.hpp
[ASharedModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/ASharedModule.hpp
[AProtectedModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AProtectedModule.hpp
[ModuleManager]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AModuleManager.hpp
[Task]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/task/ITask.hpp
[Response]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/http/Response.hpp
[DataStore]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/DataStore.hpp
[Step]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/Step.hpp
[basic logger]: https://github.com/PierreBougon/ExistenZIA/blob/master/Examples/BasicModule.cpp
[basic example]: https://github.com/PierreBougon/ExistenZIA/blob/master/Examples/BasicModule.cpp

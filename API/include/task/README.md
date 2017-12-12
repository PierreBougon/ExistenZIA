# Modules Processing
## The Task
When processing modules you need order ! which modules to execute firsts ? in which order ? 
How to add a module ? How do you process them ?

To answer those questions we came with an object : the [Task].

### [ITask](Task)
This interface ensure that a task provides the following possible features :
* Holding an execution list (that is simply a [AHTTPModules](AHTTPModule) vector)
* A client 
* Holding a [Request] sent by the client and to pass through the execution list
* Holding a [Response] to send back to client
* Various methods to get and add modules to the execution list (see [Modules] documentation)

The task is produced by a [ITaskFactory] and is pushed into the [ThreadPool] to be consumed by the worker.
When you retrieve tasks from the thread pool, a response must be set and can be sent back to the client through the 
[Network].

### [ATask]
This is the abstract implementation of the [ITask](Task) interface. It provides the basic elements
to be compliant.

The following code snippet shows the implementation of a task `Step processModules()` method:
```cpp
xzia::Step xzia::BasicTask::processModules() {
    int position = 0;
    Step step = Step::Continue;
    
    while (step == Step::Continue || position < executionList.size()) {
        step = (*executionList[position]).process(*this);
        ++position;
    }
    return step;
}
```
Here we are using a while loop because iterators might cause errors since the execution list can be modified during the modules processing.

## The TaskFactory

### [ATaskFactory]
The task factory is used to easily produce tasks.
The [BasicTask] and [BasicTaskFactory] examples provided shows how simple it is to produce tasks.

Factoring a task, once it's been _**correctly**_ implemented, is as simple as:
```cpp
std::unique_ptr<xzia::ATask> xzia::BasicTaskFactory::createTask(std::unique_ptr<xzia::Request> req, xzia::Client client) {
    return (std::make_unique<xzia::BasicTask>(req, client, moduleManager.getExecutionListModel()));
}
``` 

[Loader]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/loader
[config.json]: https://github.com/PierreBougon/ExistenZIA/blob/master/Examples/config.json
[AModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AModule.hpp
[Modules]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules
[AHTTPModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AHTTPModule.hpp
[ASharedModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/ASharedModule.hpp
[AProtectedModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AProtectedModule.hpp
[ModuleManager]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AModuleManager.hpp
[Task]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/task/ITask.hpp
[ATask]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/task/ATask.hpp
[ITaskFactory]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/task/ITaskFactory.hpp
[ATaskFactory]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/task/ATaskFactory.hpp
[Response]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/http/Response.hpp
[Request]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/http/Request.hpp
[DataStore]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/DataStore.hpp
[Step]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/Step.hpp
[basic logger]: https://github.com/PierreBougon/ExistenZIA/blob/master/Examples/BasicModule.cpp
[basic example]: https://github.com/PierreBougon/ExistenZIA/blob/master/Examples/BasicModule.cpp
[ThreadPool]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/thread/IThreadPool
[Network]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/network/INetwork.hpp
[BasicTask]: https://github.com/PierreBougon/ExistenZIA/blob/Examples/BasicTask.hpp
[BasicTaskFactory]: https://github.com/PierreBougon/ExistenZIA/blob/Examples/BasicTaskFactory.hpp
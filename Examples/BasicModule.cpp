#include "modules/AModuleManager.hpp"
#include "task/ATask.hpp"
#include "BasicModule.hpp"


int xzia::BasicModule::do_some_operation(const xzia::Message &message, int multiplyBy)
{
    return (std::stoi(message.body) * multiplyBy);
}

/*
 * 1. Checking if some modules passed data to our BasicModule dataStore
 * 2. Getting the actual data
 * 3. Checking if the request has a body
 * 4. Executing the operation method that take our request, and process it
 * 5. Pushing the value into the next module called "Processor" dataStore.
 * 6. Creating a new module from the module manager
 * 7. Adding a new module at the end of the task list
 * 8. Adding a new module just after our current module
 * 9. Creating a new dataStore, adding data to it
 * 10. Getting a shared module and passing a DataStore to it
 * last. Returning Continue to tell the task to proceed to the next module in its executionList
 */
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

xzia::BasicModule::BasicModule(std::string const &name, xzia::AModuleManager &moduleManager) :
        AHTTPModule(name, moduleManager)
{
}
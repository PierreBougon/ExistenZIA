//
// Created by 53818 on 11/12/2017.
//

#include "task/ATask.hpp"
#include "BasicModule.hpp"


int xzia::BasicModule::do_some_operation(const xzia::Message &message, int multiplyBy) {
    return (std::stoi(message.body) * multiplyBy);
}

/*
 * 1. Checking if some modules passed data to our BasicModule dataStore
 * 2. Getting the actual data
 * 3. Checking if the request has a body
 * 4. Executing the operation method that take our request, and process it
 * 5. Pushing the value into the next module called "Processor" dataStore.
 * 6. Returning Continue to tell the task to proceed to the next module in its executionList
 */
xzia::Step xzia::BasicModule::process(xzia::ATask &task)
{
    int multiplyBy = 100;

    if (dataStore.hasData("multiply_by")) // 1
    {
        multiplyBy = dataStore.getData<int>("multiply_by"); // 2
    }


    if (task.getRequest().hasBody()) // 3
    {
        int value_to_pass = do_some_operation(task.getRequest(), multiplyBy); // 4
        task.getNextModule("Processor").dataStore.addData<int>("value", value_to_pass); // 5
    }

    return xzia::Step::Continue; // 6
}

xzia::BasicModule::BasicModule(std::string const &name, xzia::AModuleManager &moduleManager) :
        AHTTPModule(name, moduleManager)
{
}
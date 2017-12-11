//
// Created by 53818 on 11/12/2017.
//

#include "task/ATask.hpp"
#include "BasicModule.hpp"


int xzia::BasicModule::do_some_operation(const xzia::Message &message) {
    return (std::stoi(message.body) * 150);
}

xzia::Step xzia::BasicModule::process(xzia::ATask &task) {
    if (task.getRequest().hasBody())
    {
        int value_to_pass = do_some_operation(task.getRequest());

        // Adding data to be processed by the next module called Processor in the task execution list
        task.getNextModule("Processor").dataStore.addData<int>("value", value_to_pass);
    }
    return xzia::Step::Continue;
}

xzia::BasicModule::BasicModule(std::string const &name, xzia::AModuleManager &moduleManager) :
        AHTTPModule(name, moduleManager)
{
}
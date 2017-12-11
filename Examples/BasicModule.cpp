//
// Created by 53818 on 11/12/2017.
//

#include "task/ATask.hpp"
#include "BasicModule.hpp"

xzia::Step xzia::BasicModule::process(xzia::ATask &task) {
    if (task.getRequest().hasBody())

    return xzia::Step::Continue;
}

xzia::BasicModule::BasicModule(std::string const &name, xzia::AModuleManager &moduleManager) :
        AHTTPModule(name, moduleManager)
{
}

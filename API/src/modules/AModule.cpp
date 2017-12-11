//
// Created by Pierre Bougon on 14/11/17.
//

#include "modules/AModule.hpp"

xzia::AModule::AModule(std::string const &name, AModuleManager &moduleManager)
        : name(name), moduleManager(moduleManager)
{
}

const std::string &xzia::AModule::getName() const
{
    return name;
}

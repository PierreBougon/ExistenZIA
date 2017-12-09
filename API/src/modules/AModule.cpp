//
// Created by Pierre Bougon on 14/11/17.
//

#include "modules/AModule.hpp"

xzia::AModule::AModule(std::string const &name, AModuleManager &moduleManager, AModule::Type type)
        : name(name), moduleManager(moduleManager), type(type)
{
}

const std::string &xzia::AModule::getName() const
{
    return name;
}

xzia::AModule::Type xzia::AModule::getType() const {
    return type;
}


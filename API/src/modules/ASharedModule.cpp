//
// Created by 53818 on 09/12/2017.
//

#include "modules/ASharedModule.hpp"

xzia::ASharedModule::ASharedModule(std::string const &name, xzia::AModuleManager &manager)
    : AModule(name, manager, AModule::Type::SHARED)
{

}

xzia::ASharedModule::ASharedModule(std::string const &name, xzia::AModuleManager &manager, xzia::AModule::Type type)
        : AModule(name, manager, type)
{
}

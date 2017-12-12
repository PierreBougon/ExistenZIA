
#include <string>
#include "modules/AModuleManager.hpp"

xzia::AHTTPModule::AHTTPModule(const std::string &name, AModuleManager &manager) :
    AModule(name, manager)
{

}

xzia::AHTTPModule::AHTTPModule(const xzia::AHTTPModule &ahttpModule) :
    AModule(ahttpModule.name, ahttpModule.moduleManager),
    dataStore(ahttpModule.dataStore)
{
}

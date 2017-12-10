
#include <string>
#include "modules/AModuleManager.hpp"

xzia::AHTTPModule::AHTTPModule(const std::string &name, AModuleManager &manager) :
    AModule(name, manager, AModule::Type::HTTP)
{

}

xzia::AHTTPModule::AHTTPModule(const xzia::AHTTPModule &ahttpModule) :
    AModule(ahttpModule.name, ahttpModule.moduleManager, ahttpModule.type),
    dataStore(ahttpModule.dataStore)
{
}

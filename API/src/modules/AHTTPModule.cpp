
#include <string>
#include "modules/AModuleManager.hpp"

xzia::AHTTPModule::AHTTPModule(const std::string &name, AModuleManager &manager) :
    AModule(name, manager, AModule::Type::HTTP)
{

}

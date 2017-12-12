//
// Created by Pierre Bougon on 20/11/17.
//

#include "modules/AProtectedModule.hpp"

xzia::Step xzia::AProtectedModule::process(xzia::DataStore &dataStore)
{
    Step ret;

    mutex.lock();
    ret = safeProcess(dataStore);
    mutex.unlock();
    return ret;
}

xzia::AProtectedModule::AProtectedModule(std::string const &name, xzia::AModuleManager &moduleManager) :
    ASharedModule(name, moduleManager)
{

}

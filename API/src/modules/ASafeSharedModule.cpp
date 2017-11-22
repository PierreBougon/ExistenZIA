//
// Created by Pierre Bougon on 20/11/17.
//

#include "modules/ASafeSharedModule.hpp"

xzia::Step xzia::ASafeSharedModule::process(xzia::DataStore &dataStore)
{
    Step ret;

    mutex.lock();
    ret = safeProcess(dataStore);
    mutex.unlock();
    return ret;
}

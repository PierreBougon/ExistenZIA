//
// Created by 53818 on 11/12/2017.
//

#include <iostream>
#include "BasicLogger.hpp"

/*
 * 1. Locking the mutex
 * 2. unlocking it
 * 3. returning Continue
 */
xzia::Step xzia::BasicLogger::process(xzia::DataStore &dataStore)
{
    mutex.lock(); // 1
    if (dataStore.hasData("log"))
    {
        std::string toLog = dataStore.getData<std::string>("log");
        std::cout << "BASIC LOG: " << toLog << std::endl;
    }
    mutex.unlock(); // 2
    return Step::Continue; // last
}

xzia::BasicLogger::BasicLogger(const std::string &name, xzia::AModuleManager &manager) :
        ASharedModule(name, manager) {}

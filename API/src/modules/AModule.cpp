//
// Created by Pierre Bougon on 14/11/17.
//

#ifdef __linux__
# include <dlfcn.h>
#elif _WIN32
# include <windows.h>
#endif

#include "modules/AModule.hpp"

xzia::AModule::AModule(std::string const &name, AModuleManager &moduleManager)
        : name(name), moduleManager(moduleManager)
{
}

const std::string &xzia::AModule::getName() const
{
    return name;
}

#ifdef __linux__
void xzia::AModule::setHandle(void *dlHandle)
#elif _WIN32
void xzia::AModule::setHandle(HINSTANCE dlHandle)
#endif
{
    this->dlHandle = dlHandle;
}


xzia::AModule::~AModule() {
#ifdef __linux__
    dlclose(dlHandle);
#elif _WIN32
    FreeLibrary(dlHandle);
#endif
}


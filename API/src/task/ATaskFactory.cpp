//
// Created by Pierre Bougon on 10/12/17.
//

#include "modules/AModuleManager.hpp"
#include "task/ATaskFactory.hpp"

xzia::ATaskFactory::ATaskFactory(xzia::AModuleManager const &moduleManager)
        : moduleManager(moduleManager)
{

}

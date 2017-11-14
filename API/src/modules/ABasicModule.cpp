//
// Created by Pierre Bougon on 13/11/17.
//

#include <core/ICore.hpp>
#include "modules/ABasicModule.hpp"

xzia::Step xzia::ABasicModule::processHTTP(xzia::IMessage &req, xzia::IMessage &res, xzia::ATask &task) {
    return xzia::Step::CONTINUE;
}

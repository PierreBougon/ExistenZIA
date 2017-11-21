//
// Created by Pierre Bougon on 13/11/17.
//

#include <core/ICore.hpp>
#include "modules/AHTTPModule.hpp"

xzia::Step xzia::AHTTPModule::processHTTP(xzia::IMessage &req, xzia::IMessage &res, xzia::ATask &task) {
    return xzia::Step::CONTINUE;
}

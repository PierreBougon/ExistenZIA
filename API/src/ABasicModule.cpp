//
// Created by Pierre Bougon on 13/11/17.
//

#include <core/ICore.hpp>
#include "modules/ABasicModule.hpp"

xzia::Step xzia::ABasicModule::process(xzia::IMessage &message, xzia::IMessage &iMessage, xzia::ATask &task) {
    return xzia::Step::CONTINUE;
}

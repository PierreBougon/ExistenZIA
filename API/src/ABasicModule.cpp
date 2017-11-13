//
// Created by Pierre Bougon on 13/11/17.
//

#include <ICore.hpp>
#include "ABasicModule.hpp"

xzia::Step xzia::ABasicModule::process(xzia::IMessage &message, xzia::IMessage &iMessage, xzia::ATask &task) {
    return xzia::Step::CONTINUE;
}

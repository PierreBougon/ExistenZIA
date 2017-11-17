//
// Created by Pierre Bougon on 14/11/17.
//

#include "modules/AModule.hpp"

xzia::AModule::AModule(AModule::Type moduleType, const std::string &name, std::mutex &mutex)
        : type(moduleType), name(name), mutex(mutex)
{
}

xzia::Step xzia::AModule::process(xzia::IMessage &req, xzia::IMessage &res, xzia::ATask &task) {
    if (type == Type::http)
        return processHTTP(req, res, task);
    else
        return processBasic();
}

xzia::AModule::Type xzia::AModule::getType() const {
    return type;
}

const std::string &xzia::AModule::getName() const {
    return name;
}

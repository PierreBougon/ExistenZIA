//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IMODULE_HPP
#define EXISTENZIA_IMODULE_HPP

#include <iostream>
#include <memory>
#include "IMessage.hpp"
#include "ATask.hpp"
#include "ICore.hpp"
#include "IModuleFactory.hpp"
#include "ILoader.hpp"

class IModule {
public:
    virtual xzia::Step process(IMessage &, IMessage &, ATask &) = 0;
    virtual xzia::Step process() = 0;
    virtual std::unique_ptr<IModule> clone() = 0;
    virtual void config(ILoader &, IModuleFactory &) = 0;
};

#endif //EXISTENZIA_IMODULE_HPP

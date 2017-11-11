//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IMODULEFACTORY_HPP
#define EXISTENZIA_IMODULEFACTORY_HPP

#include <iostream>
#include <memory>
#include "IModule.hpp"

class IModuleFactory {
public:
    virtual void add(std::string const&) = 0;
    virtual void delet(std::string const&) = 0;
    virtual std::unique_ptr<IModule> getInstance(std::string const&) = 0;
};

#endif //EXISTENZIA_IMODULEFACTORY_HPP

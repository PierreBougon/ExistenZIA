//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_AHTTPMODULE_HPP
#define EXISTENZIA_AHTTPMODULE_HPP

#include "AModule.hpp"

namespace xzia
{
    class AHTTPModule : AModule
    {
    public:
        xzia::Step process(IMessage &message, IMessage &iMessage, ATask &task) override = 0;

        xzia::Step process() final;
    };
}

#endif //EXISTENZIA_AHTTPMODULE_HPP

//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ABASICMODULE_HPP
#define EXISTENZIA_ABASICMODULE_HPP

#include "AModule.hpp"

namespace xzia {
    class ABasicModule : AModule {
    public:
        xzia::Step process(IMessage &message, IMessage &iMessage, ATask &task) final;

        xzia::Step process() override = 0;
    };
}

#endif //EXISTENZIA_ABASICMODULE_HPP

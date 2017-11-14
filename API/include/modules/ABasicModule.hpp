//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ABASICMODULE_HPP
#define EXISTENZIA_ABASICMODULE_HPP

#include "AModule.hpp"

namespace xzia {
    class ABasicModule : AModule {
    public:
        Step processHTTP(IMessage &req, IMessage &res, ATask &task) override;
    };
}

#endif //EXISTENZIA_ABASICMODULE_HPP

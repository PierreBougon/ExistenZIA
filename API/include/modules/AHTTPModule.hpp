//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_AHTTPMODULE_HPP
#define EXISTENZIA_AHTTPMODULE_HPP

#include "AModule.hpp"

namespace xzia {
    class AHTTPModule : AModule {
    public:
        xzia::Step process() final;
    };
}

#endif //EXISTENZIA_AHTTPMODULE_HPP
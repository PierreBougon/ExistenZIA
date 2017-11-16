//
// Created by duhieub on 11/16/17.
//

#ifndef EXISTENZIA_TASK_HPP
#define EXISTENZIA_TASK_HPP

#include <memory>
#include <vector>
#include "IRequest.hpp"
#include "IResponse.hpp"
#include "AHTTPModule.hpp"
#include "IClient.hpp"

namespace xzia {
    struct Task {
        std::unique_ptr<IRequest> req;
        IResponse rep;
        IClient &client;
        std::vector<AHTTPModule> modules;
    };
}

#endif //EXISTENZIA_TASK_HPP

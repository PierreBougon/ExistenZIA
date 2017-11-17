//
// Created by duhieub on 11/16/17.
//

#ifndef EXISTENZIA_TASK_HPP
#define EXISTENZIA_TASK_HPP

#include <memory>
#include <vector>
#include "Request.hpp"
#include "Response.hpp"
#include "ABasicModule.hpp"
#include "Client.hpp"

/**
 * \file Task.hpp
 * \brief
 * \author Benjamin.D
 * \version 0.1
 * \date 17 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \struct Task Task.hpp Task.hpp
 *
 */
namespace xzia {
    struct Task {
        std::unique_ptr<Request> req;
        Response rep;
        Client &client;
        std::vector<ABasicModule> modules;
    };
}

#endif //EXISTENZIA_TASK_HPP

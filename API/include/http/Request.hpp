//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IREQUEST_HPP
#define EXISTENZIA_IREQUEST_HPP

#include <iostream>
#include "Message.hpp"

/**
 * \file Request.hpp
 * \brief Request is a specific message which goal is to ask something and wait for a response.
 * \author Benjamin.D
 * \version 0.1
 * \date 17 novembre 2017
 * \namespace xzia
 * \struct Request Request.hpp Request.hpp
 */

namespace xzia
{
    struct Request : Message
    {
        virtual ~Request() = default;

        std::string                             method;
        std::string                             version;
        std::string                             host;
        std::string                             port;
        std::string                             path;
        std::map<std::string, std::string>      query;
    };
}
#endif //EXISTENZIA_IREQUEST_HPP

//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_RESPONSE_HPP
#define EXISTENZIA_RESPONSE_HPP

#include "Message.hpp"

/**
 * \file Response.hpp
 * \brief Response is a specific message which goal is to return a message containing the result code of the task asked.
 * \author Pierre.B
 * \version 0.1
 * \date 13 novembre 2017
 * \namespace xzia
 * \struct Response Response.hpp Response.hpp
 */
namespace xzia
{
    struct Response : Message
    {
        int     code;

        explicit Response(Client client);
        virtual ~Response() = default;
    };
}

#endif //EXISTENZIA_IRESPONSE_HPP

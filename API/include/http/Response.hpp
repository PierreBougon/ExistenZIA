//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_RESPONSE_HPP
#define EXISTENZIA_RESPONSE_HPP

#include "Message.hpp"

/**
 * \file Response.hpp
 * \brief
 * \author Pierre.B
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class Response Response.hpp Response.hpp
 */
namespace xzia
{
    struct Response : Message
    {
        int     code;
    };
}

#endif //EXISTENZIA_IRESPONSE_HPP

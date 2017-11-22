//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_MESSAGE_HPP
#define EXISTENZIA_MESSAGE_HPP

#include <iostream>
#include <map>
#include <client/Client.hpp>

/**
 * \file Message.hpp
 * \brief
 * \author Robin.U
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class Message Message.hpp Message.hpp
 *
 */
namespace xzia
{
    struct Message
    {
        std::string                             body;
        std::string                             version;
        std::map<std::string, std::string>      header;
        Client const                            &client;

        /**
         *
         * \fn hasBody
         * \brief
         * @return Return True if the message has a body, else false
         *
         */
        bool hasBody();
    };
}

#endif //EXISTENZIA_MESSAGE_HPP

//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IMESSAGE_HPP
#define EXISTENZIA_IMESSAGE_HPP

#include <iostream>

/**
 * \file IMessage.hpp
 * \brief
 * \author Robin.U
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class IHeader IHeader.hpp IHeader.hpp
 * \class IMessage IMessage.hpp IMessage.hpp
 *
 */
namespace xzia {

    class IHeader;
    class IMessage {
    public:

        /**
         *
         * \fn hasBody
         * \brief
         * @return Return True if the message has a body, else false
         *
         */
        virtual bool hasBody() = 0;

        /**
         *
         * \fn getBody
         * \brief
         * @return Return a string representing the current body of the message
         *
         */
        virtual std::string &getBody() const = 0;

        /**
         *
         * \fn setBody
         * \brief
         * @param body New body we want to set to the current message
         *
         */
        virtual void setBody(std::string const &body) = 0;

        /**
         *
         * \fn getHeader
         * \brief
         * @return Return the current header of type IHeader
         *
         */
        virtual IHeader &getHeader() const = 0;
    };
}

#endif //EXISTENZIA_IMESSAGE_HPP

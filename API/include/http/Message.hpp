//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_MESSAGE_HPP
#define EXISTENZIA_MESSAGE_HPP

#include <iostream>
#include "Header.hpp"

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
namespace xzia {

    class Message {
    private:
        Header      head;
        std::string body;
        std::string version;

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
        void setBody(std::string const &body);

        /**
         *
         * \fn getHeader
         * \brief
         * @return Return the current header of type IHeader
         *
         */
        Header &getHeader() const;

        /**
         *
         * \fn getVersion
         * \brief
         * @return
         *
         */
        std::string getVersion() const;

        /**
         *
         * \fn setHeader
         * \brief
         * @param head
         *
         */
        void setHeader(Header const &head);

        /**
         *
         * \fn setVersion
         * \brief
         * @param version
         *
         */
        void setVersion(std::string const &version);
    };
}

#endif //EXISTENZIA_MESSAGE_HPP

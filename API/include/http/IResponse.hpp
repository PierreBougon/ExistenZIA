//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IRESPONSE_HPP
#define EXISTENZIA_IRESPONSE_HPP

#include "IMessage.hpp"

/**
 * \file IResponse.hpp
 * \brief
 * \author Pierre.B
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class IMessage IMessage.hpp IMessage.hpp
 * \class IResponse IResponse.hpp IResponse.hpp
 */
namespace xzia {
    class IResponse : public IMessage {
    public:

        /**
         * \fn hasBody
         * \brief
         * @return Return True if the message has a body, else false
         *
         */
        bool hasBody() override = 0;

        /**
         *
         * \fn getBody
         * \brief
         * @return Return a string representing the current body of the message
         *
         */
        std::string &getBody() override = 0;

        /**
         *
         * \fn setBody
         * \brief
         * @param body New body we want to set to the current message
         *
         */
        void setBody(std::string const &body) override = 0;

        /**
         *
         * \fn getHeader
         * \brief
         * @return Return the current header of type IHeader
         *
         */
        IHeader &getHeader() override = 0;

        /**
         *
         * \fn setHeader
         * \brief Set a header to the response
         * @param string String representing the header
         *
         */
        virtual void setHeader(std::string const &header) = 0;

        /**
         *
         * \fn setCode
         * \brief Set a code to the response
         * @param code String representing the code
         *
         */
        virtual void setCode(std::string const &code) = 0;

        /**
         *
         * \fn getCode
         * \brief get the code of the response
         * @return String of the current code contain in the response
         *
         */
        virtual std::string &getCode() const = 0;
    };
}

#endif //EXISTENZIA_IRESPONSE_HPP

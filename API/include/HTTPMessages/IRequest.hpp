//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IREQUEST_HPP
#define EXISTENZIA_IREQUEST_HPP

#include <iostream>
#include "IMessage.hpp"

/**
 * \file IRequest.hpp
 * \brief
 * \author Benjamin.D
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class IMessage IMessage.hpp IMessage.hpp
 * \class IRequest IRequest.hpp IRequest/hpp
 */

namespace xzia {

    class IRequest : IMessage {

        /**
         *
         * \fn hasBody
         * \brief Determine if the message has a body
         * @return Return true if the Request has a body, else false
         *
         */
        virtual bool hasBody() = 0;

        /**
         *
         * \fn getBody
         * \brief get the current body of the request
         * @return Return a string representing the current body of the request
         *
         */
        virtual std::string &getBody() const = 0;

        /**
         *
         * \fn setBody
         * \brief Set a body to the request
         * @param string String representing the body of the message
         *
         */
        virtual void setBody(std::string const &string) = 0;

        /**
         *
         * \fn getHeader
         * \brief Get the header of the request
         * @return Return a string representing the header.
         *
         */
        virtual IHeader &getHeader() const = 0;

        /**
         *
         * \fn setHeader
         * \brief Set a header to the request
         * @param string String representing the header
         *
         */
        virtual void setHeader(std::string const &string) = 0;

        /**
         *
         * \fn getMethod
         * \brief
         * @return Return a string representing the method
         *
         */
        virtual std::string & getMethod() const = 0;

        /**
         * \fn getVersion
         * \brief
         * @return Return a string representing the version
         *
         */
        virtual std::string & getVersion() const = 0;

        /**
         *
         * \fn getURLHost
         * \brief
         * @return Return a string representing the URL host
         *
         */
        virtual std::string & getURLHost() const = 0;

        /**
         *
         * \fn getURLPort
         * \brief
         * @return Return a string representing the URL port
         *
         */
        virtual std::string & getURLPort() const = 0;

        /**
         *
         * \fn getURLPath
         * \brief
         * @return Return a string representing the URL path
         */
        virtual std::string & getURLPath() const = 0;

        /**
         *
         * \fn getURLQuery
         * \brief
         * @param field String representing the field
         * @return Return a string representing the URL query
         *
         */
        virtual std::string & getURLQuery(std::string const & field) const = 0;

        /**
         *
         * \fn setMethod
         * \brief Set a method to the request
         * @param method String representing the method
         *
         */
        virtual void setMethod(std::string const &method) = 0;

        /**
         *
         * \fn setVersion
         * \brief Set a version to the request
         * @param version String representing the version
         *
         */
        virtual void setVersion(std::string const &version) = 0;

        /**
         *
         * \fn setURLHost
         * \brief Set the URL host to the request
         * @param host String representing the URL host
         *
         */
        virtual void setURLHost(std::string const &host) = 0;

        /**
         *
         * \fn setURLPort
         * \brief Set the URL port to the request
         * @param port String representing the URL port
         *
         */
        virtual void setURLPort(std::string const &port) = 0;

        /**
         *
         * \fn setURLPath
         * \brief Set the URL path to the request
         * @param path String representing the URL path
         *
         */
        virtual void setURLPath(std::string const &path) = 0;

        /**
         *
         * \fn setURLQuery
         * \brief Set the URL query to the request
         * @param field //TODO Describe this param here
         * @param value //TODO Describe this param here
         *
         */
        virtual void setURLQuery(std::string const & field, std::string const & value) = 0;

        /**
         *
         * \fn deleteURLQuery
         * \brief Remove a specific URL query contain in the request
         * @param field //TODO Describe this param here
         *
         */
        virtual void deleteURLQuery(std::string const & field) = 0;
    };
}
#endif //EXISTENZIA_IREQUEST_HPP

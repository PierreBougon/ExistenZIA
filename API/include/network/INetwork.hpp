//
// Created by Pierre Bougon on 22/11/17.
//

#ifndef ZIA_INETWORK_HPP_
#define ZIA_INETWORK_HPP_

#include <http/Request.hpp>
#include <bits/unique_ptr.h>
#include <vector>
#include <http/Response.hpp>

/**
 * \file INetwork.hpp
 * \brief Network is the class which link Core (Arrival of a message, and send the message response) to the client
 * \author Edouard.E
 * \version 0.2
 * \date 10 December 2017
 * \namespace xzia
 * \class INetwork INetwork.hpp INetwork.hpp
 *
 */
namespace xzia
{
    class INetwork
    {
    public:

        /**
        *
        * \fn start
        * \brief Launch the link between the core and the client
        *
        */
        virtual void start() = 0;

        /**
        *
        * \fn  popRequest
        * \brief Take the first request in the queue, then prepare to apply it
        * @return Return a Message of type request from the queue of request.
        *
        */
        virtual std::unique_ptr<Request> popRequest() = 0;

        /**
        *
        * \fn getAllRequests
        * \brief Take all the last request in the queue, then prepare to apply them
        * @return Return all the last request from the queue of request
        *
        */
        virtual std::vector<std::unique_ptr<Request>> getAllRequests() = 0;

        /**
        *
        * \fn sendResponse
        * \brief Following the handling of a request , send the message response to the client.
        * @param res Contain the message code response from the last request
        *
        */
        virtual void sendResponse(std::unique_ptr<Response> res) = 0;

        /**
        *
        * \fn sendAllResponses
        * \brief Following the handling of all the last request , send the messages response to the client.
        * @param listRes Contain respectively all the response codes from the queue of request
        *
        */
        virtual void sendAllResponses(std::vector<std::unique_ptr<Response>> listRes) = 0;
    };
}

#endif // !ZIA_INETWORK_HPP_

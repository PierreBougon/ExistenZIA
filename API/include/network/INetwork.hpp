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
 * \brief
 * \author Edouard.E
 * \version 0.2
 * \date 10 December 2017
 *
 * add comment here
 *
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
        * \brief
        *
        */
        virtual void start() = 0;

        /**
        *
        * \fn  popRequest
        * \brief
        * @return
        *
        */
        virtual std::unique_ptr<Request> popRequest() = 0;

        /**
        *
        * \fn getAllRequests
        * \brief
        * @return
        *
        */
        virtual std::vector<std::unique_ptr<Request>> getAllRequests() = 0;

        /**
        *
        * \fn sendResponse
        * \brief
        * @param res
        *
        */
        virtual void sendResponse(std::unique_ptr<Response> res) = 0;

        /**
        *
        * \fn sendAllResponses
        * \brief
        * @param listRes
        *
        */
        virtual void sendAllResponses(std::vector<std::unique_ptr<Response>> listRes) = 0;
    };
}

#endif // !ZIA_INETWORK_HPP_

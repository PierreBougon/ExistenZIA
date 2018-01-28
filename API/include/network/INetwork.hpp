//
// Created by Pierre Bougon on 22/11/17.
//

#ifndef ZIA_INETWORK_HPP_
#define ZIA_INETWORK_HPP_

#include <bits/unique_ptr.h>
#include <vector>
#include "sza/api/net.h"
#include "sza/api/http.h"

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
    class INetwork: zia::api::Net
    {
     private:
      /**
        *
        * \fn  callBackFunction
        * \brief Activate when client send raw data, store them as Duplex
        * in queue
        * @param data The raw data get by client
        * @param info From which and when the data are received
        *
        */
      virtual void callBackFunction(Raw data, zia::api::NetInfo info) = 0;
    public:
        virtual ~INetwork() = default;

        /**
        *
        * \fn  popRequest
        * \brief Take the first request in the queue, then prepare to apply it
        * @return Return a Message of type request from the queue of request.
        *
        */
        virtual std::unique_ptr<zia::api::HttpDuplex> popRequest() = 0;

        /**
        *
        * \fn getAllRequests
        * \brief Take all the last request in the queue, then prepare to apply them
        * @return Return all the last request from the queue of request
        *
        */
        virtual std::vector<std::unique_ptr<zia::api::HttpDuplex>> getAllRequests() = 0;
    };
}

#endif // !ZIA_INETWORK_HPP_

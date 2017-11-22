//
// Created by Pierre Bougon on 22/11/17.
//

#ifndef ZIA_INETWORK_HPP_
#define ZIA_INETWORK_HPP_

#include <http/Request.hpp>
#include <bits/unique_ptr.h>
#include <vector>
#include <http/Response.hpp>

namespace xzia
{
    class INetwork
    {
    public:
        virtual void start() = 0;

        virtual std::unique_ptr<Request> popRequest() = 0;

        virtual std::vector<std::unique_ptr<Request>> getAllRequests() = 0;

        virtual void sendResponse(std::unique_ptr<Response> res) = 0;

        virtual void sendAllResponses(std::vector<std::unique_ptr<Response>> listRes) = 0;
    };
}

#endif // !ZIA_INETWORK_HPP_

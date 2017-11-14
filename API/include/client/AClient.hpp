//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ACLIENT_HPP
#define EXISTENZIA_ACLIENT_HPP

#include <vector>
#include "IClient.hpp"
#include "http/IResponse.hpp"

namespace xzia
{
    class AClient : IClient
    {
    protected:
        int                     socket;
        std::vector<IRequest &> listRequest;
        IResponse               &response;
    };
}

#endif //EXISTENZIA_ACLIENT_HPP

//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ATASK_HPP
#define EXISTENZIA_ATASK_HPP

#include <string>
#include <vector>
#include "client/Client.hpp"
#include "modules/AHTTPModule.hpp"
#include "http/Request.hpp"
#include "http/Response.hpp"
#include "modules/Step.hpp"
#include "ITask.hpp"

namespace xzia
{
    class ATask : public ITask
    {
    public:
        ATask() = delete;
        ATask(std::string name, Client &client,
              std::vector<std::unique_ptr<AHTTPModule>> executionList);

    protected:
        std::string                 name;
        std::unique_ptr<Request>    req;
        Response                    res;
        Client                      &client;

        std::vector<std::unique_ptr<AHTTPModule>> executionList;
    };
}

#endif //EXISTENZIA_ATASK_HPP

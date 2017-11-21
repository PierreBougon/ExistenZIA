//
// Created by Pierre Bougon on 20/11/17.
//

#include "task/ATask.hpp"

xzia::ATask::ATask(std::unique_ptr<Request> req, xzia::Client &client,
                   std::vector<std::unique_ptr<xzia::AHTTPModule>> executionList)
        : client(client), executionList(executionList)
{
    this->req = std::move(req);
}

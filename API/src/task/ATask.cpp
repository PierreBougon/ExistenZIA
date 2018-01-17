//
// Created by Pierre Bougon on 20/11/17.
//

#include "task/ATask.hpp"

xzia::ATask::ATask(std::unique_ptr<zia::api::HttpDuplex> req,
                   std::vector<std::unique_ptr<xzia::AHTTPModule>> executionList)
        : executionList(std::move(executionList))
{
    this->req = std::move(req);
}

//
// Created by Pierre Bougon on 20/11/17.
//

#include "task/ATask.hpp"

xzia::ATask::ATask(std::string name, xzia::Client &client,
                   std::vector<std::unique_ptr<xzia::AHTTPModule>> executionList)
        : name(name), client(client), executionList(executionList)
{
}

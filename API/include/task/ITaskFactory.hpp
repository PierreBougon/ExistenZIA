//
// Created by Pierre Bougon on 10/12/17.
//

#ifndef ZIA_ITASKFACTORY_HPP_
#define ZIA_ITASKFACTORY_HPP_

#include <memory>
#include "task/ATask.hpp"

namespace xzia
{
    class ITaskFactory
    {
    public:
        virtual ~ITaskFactory() = default;

        virtual std::unique_ptr<ATask> createTask(std::unique_ptr<Request> req, Client
                                                  client) = 0;
    };
}

#endif // !ZIA_ITASKFACTORY_HPP_

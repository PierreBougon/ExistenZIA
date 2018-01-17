//
// Created by Pierre Bougon on 10/12/17.
//

#ifndef ZIA_ITASKFACTORY_HPP_
#define ZIA_ITASKFACTORY_HPP_

#include <memory>
#include "task/ATask.hpp"

/**
 * \file ITaskFactory.hpp
 * \brief The ITaskFactory Interface generate the task for a request from a client
 * \author Pierre.B
 * \version 0.2
 * \date 10 December 2017
 *
 *
 *
 * \namespace xzia
 * \class ITaskFactory ITaskFactory.hpp
 *
 */
namespace xzia
{
    class ITaskFactory
    {
    public:
        virtual ~ITaskFactory() = default;

        virtual std::unique_ptr<ATask> createTask(std::unique_ptr<zia::api::HttpDuplex> req) = 0;
    };
}

#endif // !ZIA_ITASKFACTORY_HPP_

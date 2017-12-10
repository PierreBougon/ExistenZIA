//
// Created by Pierre Bougon on 10/12/17.
//

#ifndef ZIA_ATASKFACTORY_HPP_
#define ZIA_ATASKFACTORY_HPP_

#include "ITaskFactory.hpp"

/**
 * \file ATaskFactory.hpp
 * \brief ATaskFactory generate a task with the help of the module manager
 * \author Pierre.B
 * \version 0.2
 * \date 10 December 2017
 * \namespace xzia
 * \class ATaskFactory ATaskFactory.hpp
 *
 */
namespace xzia
{
    class ATaskFactory : ITaskFactory
    {
    public:
        ATaskFactory() = delete;
        explicit ATaskFactory(AModuleManager const &moduleManager);
        virtual ~ATaskFactory() {};

    protected:
        AModuleManager const &moduleManager;
    };
}

#endif // !ZIA_ATASKFACTORY_HPP_

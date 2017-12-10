//
// Created by Pierre Bougon on 10/12/17.
//

#ifndef ZIA_ATASKFACTORY_HPP_
#define ZIA_ATASKFACTORY_HPP_

#include "ITaskFactory.hpp"

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

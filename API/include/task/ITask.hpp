//
// Created by Pierre Bougon on 13/11/17.
//

#ifndef ZIA_ITASK_HPP_
#define ZIA_ITASK_HPP_

#include <memory>
#include <vector>
#include "modules/IModule.hpp"

namespace xzia
{
    class ITask
    {
    public:
        virtual std::unique_ptr<ITask> clone() = 0;
        virtual std::vector<std::unique_ptr<IModule>> getExecutionList() = 0;
    };
}

#endif // !ZIA_ITASK_HPP_

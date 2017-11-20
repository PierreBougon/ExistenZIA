//
// Created by Pierre Bougon on 13/11/17.
//

#ifndef ZIA_ITASK_HPP_
#define ZIA_ITASK_HPP_

#include <memory>
#include <vector>
#include "modules/Step.hpp"

namespace xzia
{
    class ITask
    {
    public:
        virtual std::unique_ptr<ITask>              clone() = 0;
        virtual std::vector<std::unique_ptr<Step>>  getExecutionList() = 0;
        virtual void                                setRequest(std::unique_ptr<Request>) = 0;
    };
}

#endif // !ZIA_ITASK_HPP_

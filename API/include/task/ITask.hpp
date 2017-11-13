//
// Created by Pierre Bougon on 13/11/17.
//

#ifndef ZIA_ITASK_HPP_
#define ZIA_ITASK_HPP_

#include <memory>

namespace xzia
{
    class ITask
    {
        virtual std::unique_ptr<ITask> clone() = 0;
    };
}

#endif // !ZIA_ITASK_HPP_

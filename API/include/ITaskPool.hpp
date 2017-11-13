//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ITASKPOOL_HPP
#define EXISTENZIA_ITASKPOOL_HPP

#include "ATask.hpp"

namespace xzia
{
    class ITaskPool
    {
    protected:
        std::vector<ATask>                  listTaskModel;
        std::vector<std::unique_ptr<ATask>> listTaskCloned;
    };
}

#endif //EXISTENZIA_ITASKPOOL_HPP

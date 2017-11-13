//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ATASKPOOL_HPP
#define EXISTENZIA_ATASKPOOL_HPP

#include "ITaskPool.hpp"

namespace xzia {
    class ATaskPool : ITaskPool
    {
    protected:
        std::vector<ATask>                  listTaskModel;
        std::vector<std::unique_ptr<ATask>> listTaskCloned;
    };
}
#endif //EXISTENZIA_ATASKPOOL_HPP

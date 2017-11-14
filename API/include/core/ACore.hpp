//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ACORE_HPP
#define EXISTENZIA_ACORE_HPP

#include <vector>
#include "core/ICore.hpp"
#include "loader/ILoader.hpp"
#include "modules/IModuleFactory.hpp"
#include "task/ITaskPool.hpp"
#include "task/TaskBoard.hpp"

namespace xzia
{
    class ACore : xzia::ICore
    {
    public:
        ACore(std::string config);

    protected:
        ILoader                 &loader;
        IModuleFactory          &moduleFactory;
        ITaskPool               &taskPool;
        std::vector<TaskBoard>  listTaskBoard;

    private:
        std::string configFile;
    };
}

#endif //EXISTENZIA_ACORE_HPP

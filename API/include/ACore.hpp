//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ACORE_HPP
#define EXISTENZIA_ACORE_HPP

#include <vector>
#include "ICore.hpp"
#include "ILoader.hpp"
#include "IModuleFactory.hpp"
#include "ATaskPool.hpp"
#include "TaskBoard.hpp"

namespace xzia {
    class ACore : xzia::ICore {
    protected:
        ILoader loader;
        IModuleFactory moduleFactory;
        ITaskPool taskPool;
        std::vector<TaskBoard> taskBoards;

    public:
        ACore(std::string const &config);
        void run() override;
    };
}

#endif //EXISTENZIA_ACORE_HPP

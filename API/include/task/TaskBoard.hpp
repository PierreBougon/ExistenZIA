//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_TASKBOARD_HPP
#define EXISTENZIA_TASKBOARD_HPP

#include <thread>
#include "client/IClient.hpp"
#include "ATaskPool.hpp"

namespace xzia {
    struct TaskBoard {
        std::thread     thread;
        IClient         &client;
        ATaskPool       &taskPool;
    };
}

#endif //EXISTENZIA_TASKBOARD_HPP

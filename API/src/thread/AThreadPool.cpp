//
// Created by Pierre Bougon on 20/11/17.
//

#include "thread/AThreadPool.hpp"

xzia::AThreadPool::AThreadPool(unsigned int nbThreads)
{
    for (unsigned int i = 0; i < nbThreads; ++i)
    {
        threads.emplace_back(std::thread(&AThreadPool::threadWorkflow, this, i));
        state.push_back(ThreadState::sleeping);
    }
}

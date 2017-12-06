//
// Created by Pierre Bougon on 20/11/17.
//

#include "thread/AThreadPool.hpp"

xzia::AThreadPool::AThreadPool(unsigned int nbThreads)
{
    for (unsigned int i = 0; i < nbThreads; ++i)
    {
        threads.push_back(std::thread(threadWorkflow(i)));
        state.push_back(ThreadState::sleeping);
    }
}

//
// Created by Pierre Bougon on 15/11/17.
//

#ifndef ZIA_ATHREADPOOL_HPP_
#define ZIA_ATHREADPOOL_HPP_

#include <vector>
#include <thread>
#include <queue>
#include <atomic>
#include <condition_variable>
#include "task/ATask.hpp"
#include "IThreadPool.hpp"
#include "ThreadState.hpp"

/**
 * \file AThreadPool.hpp
 * \brief
 * \author Marc.B
 * \version 0.2
 * \date 10 December 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class AThreadPool AThreadPool.hpp AThreadPool.hpp
 *
 */
namespace xzia
{
    class AThreadPool : public IThreadPool
    {
    public:
        AThreadPool() = delete;
        AThreadPool(unsigned int nbThreads);

    protected:

        std::vector<std::thread>            threads;
        std::queue<std::unique_ptr<ATask>>  todoTasks;
        std::queue<std::unique_ptr<ATask>>  doneTasks;
        std::vector<ThreadState>            state;
        std::atomic<bool>                   running;
        std::condition_variable             condvar;
        std::mutex                          mutex;

        /**
        *
        * \fn threadWorkflow
        * \brief
        * @param id
        *
        */
        virtual void threadWorkflow(unsigned int id) = 0;
    };
}

#endif // !ZIA_ATHREADPOOL_HPP_

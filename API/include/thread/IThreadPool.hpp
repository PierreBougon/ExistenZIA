//
// Created by Pierre Bougon on 20/11/17.
//

#ifndef ZIA_ITHREADMANAGER_HPP_
#define ZIA_ITHREADMANAGER_HPP_

#include <task/ATask.hpp>

namespace xzia
{
    enum class ThreadState : unsigned char
    {
        working,
        sleeping
    };

    class IThreadPool
    {
        virtual bool    addTask(std::unique_ptr<ATask> task) = 0;
        virtual void    stop()= 0;
        virtual ATask   &getTaskDone() = 0;
    };
}

#endif // !ZIA_ITHREADMANAGER_HPP_

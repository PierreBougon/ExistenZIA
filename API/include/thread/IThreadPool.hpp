//
// Created by Pierre Bougon on 20/11/17.
//

#ifndef ZIA_ITHREADMANAGER_HPP_
#define ZIA_ITHREADMANAGER_HPP_

#include <task/ATask.hpp>

/**
 * \file IThreadPool.hpp
 * \brief Interface of our manager of threads
 * \author Edouard.E
 * \version 0.2
 * \date 10 December 2017
 * \namespace xzia
 * \class IThreadPool IThreadPool.hpp IThreadPool.hpp
 *
 */
namespace xzia
{
    class IThreadPool
    {
    public:
        virtual ~IThreadPool() = default;

        /**
        *
        * \fn addTask
        * \brief Add a task to the workFlow thread
        * @param task Task to process
        * 
        */
        virtual void    addTask(std::unique_ptr<ATask> task) = 0;

        /**
        *
        * \fn stop
        * \brief Stop the thread
        *
        */
        virtual void    stop()= 0;

        /**
        *
        * \fn getTaskDone
        * \brief Get the task done, when it's finished
        * @return Return all task done or an empty vector if no task was finished
        *
        */
        virtual std::vector<std::unique_ptr<ATask>>   getAllTaskDone() = 0;
    };
}

#endif // !ZIA_ITHREADMANAGER_HPP_

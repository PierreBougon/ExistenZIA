//
// Created by Pierre Bougon on 20/11/17.
//

#ifndef ZIA_ITHREADMANAGER_HPP_
#define ZIA_ITHREADMANAGER_HPP_

#include <task/ATask.hpp>

/**
 * \file IThreadPool.hpp
 * \brief
 * \author Edouard.E
 * \version 0.2
 * \date 10 December 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class IThreadPool IThreadPool.hpp IThreadPool.hpp
 *
 */
namespace xzia
{
    class IThreadPool
    {
        /**
        *
        * \fn threadWorkflow
        * \brief
        * @param task
        *
        */
        virtual bool    addTask(std::unique_ptr<ATask> task) = 0;

        /**
        *
        * \fn threadWorkflow
        * \brief
        *
        */
        virtual void    stop()= 0;

        /**
        *
        * \fn threadWorkflow
        * \brief
        * @return
        *
        */
        virtual ATask   &getTaskDone() = 0;
    };
}

#endif // !ZIA_ITHREADMANAGER_HPP_

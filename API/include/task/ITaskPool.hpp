//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ITASKPOOL_HPP
#define EXISTENZIA_ITASKPOOL_HPP

#include <iostream>
#include <vector>

/**
 * \file IClient.hpp
 * \brief
 * \author Marc.B
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class ATask ATask.hpp ATask.hpp
 * \class ITaskPool ITaskPool.hpp ITaskPool.hpp
 */
namespace xzia {
    class ATask;
    class ITaskPool {
    public:

        /**
         *
         * \fn addModel
         * \brief
         * @param model //TODO Describe this param here
         * @param ressource //TODO Describe this param here
         * @param moduleNames //TODO Describe this param here
         *
         */
        virtual void addModel(std::string const &model, std::string const &ressource,
                              std::vector<std::string> &moduleNames) = 0;

        /**
         *
         * \fn deleteModel
         * \brief
         * @param name //TODO Describe this param here
         *
         */
        virtual void deleteModel(std::string const &name) = 0;

        /**
         *
         * \fn getTask
         * \brief get the specific task
         * @param name
         * @return Return the specific ATask
         *
         */
        virtual ATask &getTask(std::string const &name) const = 0;

        /**
         *
         * \fn deleteTask
         * \brief Delete the task at the specific ID
         * @param id Id of the task we want to delete
         *
         */
        virtual void deleteTask(int id) = 0;
    };
}

#endif //EXISTENZIA_ITASKPOOL_HPP

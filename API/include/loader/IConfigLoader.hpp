//
// Created by duhieub on 11/16/17.
//

#ifndef EXISTENZIA_ACONFIGLOADER_HPP
#define EXISTENZIA_ACONFIGLOADER_HPP

#include <iostream>
#include <map>
#include <vector>

/**
 * \file IConfigLoader.hpp
 * \brief
 * \author Pierre.B
 * \version 0.1
 * \date 17 novembre 2017
 *
 * This interface ensure that we can ask the configuration of a specific module or the core.
 * This configuration shall appear in the form of a simple map of strings [KEY,VALUE]
 *
 * \namespace xzia
 * \class IConfigLoader
 *
 */
namespace xzia
{
    class IConfigLoader
    {
    public:

        /**
         * \fn getModuleConfig
         * \brief Retrieve the configuration of a module from the loader
         * @param module name
         * @return the configuration of the module as a map
         *
         */
        virtual std::map<std::string, std::string> getModuleConfig(std::string const &module) = 0;

        /**
         *
         * \fn getTaskList
         * \brief Retrieve the task list of modules that will processes the request received by the server
         * @return Return the name of all the tasks in a vector
         *
         */
        virtual std::vector<std::string> getTaskList() = 0;

        /**
         *
         * \fn getCoreConfig
         * \brief Retrieve the configuration of the core from the loader
         * @return the configuration of the core as a map
         *
         */
        virtual std::map<std::string, std::string> getCoreConfig() = 0;
    };
}


#endif //EXISTENZIA_ACONFIGLOADER_HPP

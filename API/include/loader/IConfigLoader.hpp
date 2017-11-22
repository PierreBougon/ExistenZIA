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
 * add comment here
 *
 * \namespace xzia
 * \class IConfigLoader IConfigLoader.hpp IConfigLoader.hpp
 *
 */
namespace xzia
{
    class IConfigLoader
    {
    public:
        /**
         * \fn getModuleMap
         * \brief
         * @param module
         * @return
         *
         */
        virtual std::map<std::string, std::string> getModuleMap(std::string module) = 0;

        /**
         *
         * \fn getTaskList
         * \brief
         * @return Return a vector containing all task represented by a string
         *
         */
        virtual std::vector<std::string> getTaskList() = 0;

        /**
         *
         * \fn getCoreMap
         * \brief
         * @return
         *
         */
        virtual std::map<std::string, std::string> getCoreMap() = 0;
    };
}


#endif //EXISTENZIA_ACONFIGLOADER_HPP

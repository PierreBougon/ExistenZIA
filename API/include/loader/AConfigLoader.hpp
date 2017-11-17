//
// Created by duhieub on 11/16/17.
//

#ifndef EXISTENZIA_ACONFIGLOADER_HPP
#define EXISTENZIA_ACONFIGLOADER_HPP

#include <iostream>
#include <map>
#include <vector>

/**
 * \file ConfigLoader.hpp
 * \brief
 * \author Pierre.B
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class ConfigLoader ConfigLoader.hpp ConfigLoader.hpp
 *
 */
namespace xzia {
    class AConfigLoader {
            /**
        * \fn getCoreField
        * \brief
        * @param field //TODO Describe this param here
        * @return Return the name of the corresponding CoreField
         *
        */
        std::string &getCoreField(std::string const &field) const;

        /**
         *
         * \fn getModule
         * \brief
         * @param module //TODO Describe this param here
         * @param field //TODO Describe this param here
         * @return Return the name of the corresponding ModuleField
         *
         */
        std::string &getModuleField(std::string const &module, std::string const &field) const;


        /**
         * \fn getModuleMap
         * \brief
         * @param module
         * @return
         *
         */
        std::map<std::string, std::string> getModuleMap(std::string module);

        /**
         *
         * \fn getTaskList
         * \brief
         * @return Return a vector containing all task represented by a string
         *
         */
        std::vector<std::string> getTaskList();

        /**
         *
         * \fn getCoreMap
         * \brief
         * @return
         *
         */
        std::map<std::string, std::string> getCoreMap();
    };
}


#endif //EXISTENZIA_ACONFIGLOADER_HPP

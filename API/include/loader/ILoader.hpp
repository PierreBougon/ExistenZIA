//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ILOADER_HPP
#define EXISTENZIA_ILOADER_HPP

#include <iostream>
#include <map>
#include <vector>

/**
 * \file ILoader.hpp
 * \brief
 * \author Edouard.P
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class ILoader ILoader.hpp ILoader.hpp
 *
 */
namespace xzia {
    class ILoader {

        /**
         *
         * \fn reload
         * \brief
         *
         */
        virtual void reload() = 0;

        /**
         * \fn getCoreField
         * \brief
         * @param field //TODO Describe this param here
         * @return Return the name of the corresponding CoreField
         *
         */
        virtual std::string &getCoreField(std::string const &field) const = 0;

        /**
         *
         * \fn getModule
         * \brief
         * @param module //TODO Describe this param here
         * @param field //TODO Describe this param here
         * @return Return the name of the corresponding ModuleField
         *
         */
        virtual std::string &getModuleField(std::string const &module, std::string const &field) const = 0;


        /**
         * \fn getMapField
         * \brief
         * @param module
         * @return
         *
         */
        virtual std::map<std::string, std::string> getMapField(std::string module) = 0;

        /**
         *
         * \fn getTaskList
         * @return Return a vector containing all task represented by a string
         *
         */
        virtual std::vector<std::string> getTaskList() = 0;

        // getMyCore
    };
}
#endif //EXISTENZIA_ILOADER_HPP

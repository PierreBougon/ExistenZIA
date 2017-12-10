//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ILOADER_HPP
#define EXISTENZIA_ILOADER_HPP

#include <iostream>
#include <map>
#include <vector>
#include "modules/AModule.hpp"

/**
 * \file ILoader.hpp
 * \brief Used to load modules and their configurations
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
namespace xzia
{
    class ILoader
    {
    public:
        virtual ~ILoader() = default;

        /**
         *
         * \fn reload
         * \brief This method allows the loader to reload the configuration, updating the list of available modules,
         * and their corresponding configuration
         *
         */
        virtual void reload() = 0;

        /**
        *
        * \fn loadModule
        * \brief This method loads a module
        * @param module
        *
        */
        virtual std::unique_ptr<AModule> loadModule(std::string const& module) = 0;
    };
}
#endif //EXISTENZIA_ILOADER_HPP

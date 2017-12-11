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
         * @return the list of the reloaded modules that need to be replaced
         */
        virtual std::vector<std::string> reload() = 0;

        /**
         * \fn notifyVersionsOutOfUse
         * @param module names from which the library is no more used and be closed
         * @param version of the corresponding module
         */
        virtual void notifyVersionsOutOfUse(std::vector<std::pair<std::string, std::uint32_t>> &&versionsOutOfUse) = 0;

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

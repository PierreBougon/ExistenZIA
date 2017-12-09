//
// Created by Pierre Bougon on 20/11/17.
//

#ifndef ZIA_IMODULEMANAGER_HPP_
#define ZIA_IMODULEMANAGER_HPP_

#include <memory>
#include <vector>
#include "AHTTPModule.hpp"
#include "ASharedModule.hpp"

/**
 * \file IModuleManager.hpp
 * \brief Interface of the module manager
 * \author Benjamin.D
 * \version 0.2
 * \date 10 December 2017
 * \namespace xzia
 * \class IModuleManager IModuleManager.hpp IModuleManager.hpp
 *
 */
namespace xzia
{
    class IModuleManager
    {
    public:
        /**
         *
         * \fn getSharedModule
         * \brief Shared module getter
         * @param module name to lookup
         * @return A reference to the shared module
         *
         */
        virtual ASharedModule &getSharedModule(std::string const &module) = 0;

        /**
         *
         * \fn getBasicModule
         * \brief HTTP module getter
         * @param module name to lookup
         * @return a HTTP module copy
         *
         */
        virtual std::unique_ptr<AHTTPModule> getHTTPModule(std::string const &module) = 0;

        /**
         *
         * \fn reload
         * \brief Notify the module manager that modules must be reloaded
         *
         */
        virtual void reload() = 0;

        /**
         *
         * \fn getTaskModules
         * \brief Execution list copier
         * @return The execution list model
         *
         */
        virtual std::vector<AHTTPModule> getExecutionListModel() = 0;
    };
}

#endif // !ZIA_IMODULEMANAGER_HPP_

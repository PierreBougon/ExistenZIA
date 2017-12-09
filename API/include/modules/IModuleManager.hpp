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
 * \brief
 * \author Benjamin.D
 * \version 0.2
 * \date 10 December 2017
 *
 * add comment here
 *
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
         * \brief
         * @param module
         * @return
         *
         */
        virtual ASharedModule &getSharedModule(std::string const &module) = 0;

        /**
         *
         * \fn getBasicModule
         * \brief
         * @param module
         * @return
         *
         */
        virtual std::unique_ptr<AHTTPModule> getHTTPModule(std::string const &module) = 0;

        /**
         *
         * \fn reload
         * \brief
         *
         */
        virtual void reload() = 0;

        /**
         *
         * \fn getTaskModules
         * \brief
         * @return
         *
         */
        virtual std::vector<AHTTPModule> getExecutionListModel() = 0;
    };
}

#endif // !ZIA_IMODULEMANAGER_HPP_

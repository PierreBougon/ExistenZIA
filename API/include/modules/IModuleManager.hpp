//
// Created by Pierre Bougon on 20/11/17.
//

#ifndef ZIA_IMODULEMANAGER_HPP_
#define ZIA_IMODULEMANAGER_HPP_

#include <bits/unique_ptr.h>
#include <vector>
#include "AHTTPModule.hpp"
#include "ASharedModule.hpp"

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

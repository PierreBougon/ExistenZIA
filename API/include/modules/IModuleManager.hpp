//
// Created by Pierre Bougon on 20/11/17.
//

#ifndef ZIA_IMODULEMANAGER_HPP_
#define ZIA_IMODULEMANAGER_HPP_

#include <vector>

namespace xzia
{
    class ASharedModule;
    class AHTTPModule;

    class IModuleManager
    {
        /**
         *
         * \fn getSharedModule
         * \brief
         * @param module
         * @return
         *
         */
        virtual ASharedModule &getSharedModule(std::string module) = 0;

        /**
         *
         * \fn getBasicModule
         * \brief
         * @param module
         * @return
         *
         */
        virtual std::unique_ptr<AHTTPModule> getHTTPModule(std::string module) = 0;

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

//
// Created by duhieub on 11/17/17.
//

#ifndef EXISTENZIA_ASHAREDMODULE_HPP
#define EXISTENZIA_ASHAREDMODULE_HPP

#include "AModule.hpp"
#include "DataStore.hpp"
#include "Step.hpp"

/**
 * \file AProtectedModule.hpp
 * \brief
 * \author Benjamin.D
 * \version 0.1
 * \date 17 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class AProtectedModule AProtectedModule.hpp AProtectedModule.hpp
 *
 */
namespace xzia
{
    class AModuleManager;

    class ASharedModule : public AModule
    {
    public:
        ASharedModule(std::string const &name, AModuleManager &manager);
        ASharedModule(std::string const &name, AModuleManager &manager, AModule::Type type);

        /**
         *
         * \fn process
         * \brief
         * @param dataStore
         * @return
         *
         */
        virtual Step process(DataStore &dataStore) = 0;

    protected:
        std::mutex mutex;
    };
}

#endif //EXISTENZIA_ASHAREDMODULE_HPP

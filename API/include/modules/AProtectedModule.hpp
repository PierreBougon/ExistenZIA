//
// Created by duhieub on 11/17/17.
//

#ifndef EXISTENZIA_ASAFESHAREDMODULE_HPP
#define EXISTENZIA_ASAFESHAREDMODULE_HPP

#include "AModule.hpp"
#include "DataStore.hpp"
#include "Step.hpp"
#include "ASharedModule.hpp"

/**
 * \file ASharedModule.hpp
 * \brief
 * \author Benjamin.D
 * \version 0.1
 * \date 17 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class ASharedModule ASharedModule.hpp ASharedModule.hpp
 *
 */
namespace xzia
{
    class AProtectedModule : public ASharedModule
    {
    public:
        /**
         * \fn
         * \brief
         * @param name
         * @param moduleManager
         */
        AProtectedModule(std::string const &name, AModuleManager &moduleManager);

        /**
         *
         * \fn process
         * \brief
         * @param dataStore
         * @return
         *
         */
        Step process(DataStore &dataStore) final;

    protected:
        /**
         *
         * \fn processData
         * \brief
         * @param dataStore
         * @return
         *
         */
        virtual Step safeProcess(DataStore &dataStore) = 0;
    };
}

#endif // EXISTENZIA_ASAFESHAREDMODULE_HPP

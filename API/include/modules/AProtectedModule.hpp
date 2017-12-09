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
 * \brief This module is protected by a mutex and can be accessed through threads. The inheriting class must implement
 * its logic in the safeProcess method instead of the process method.
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
         * \fn Constructor
         * \brief
         * @param name Module name
         * @param moduleManager Module manager reference
         */
        AProtectedModule(std::string const &name, AModuleManager &moduleManager);

        /**
         *
         * \fn process
         * \brief This method can be called at anytime by any module, it passes arguments through the DataStore.
         * @param dataStore Containing data required for the execution of the protected module
         * @return a Step that let the ThreadPool know if it can continue to the next module or stop and send a response
         *
         */
        Step process(DataStore &dataStore) final;

    protected:
        /**
         *
         * \fn processData
         * \brief This method is called by the process method. The logic of the module shall be coded here.
         * This method IS thread safe, but if your logic is heavy and requires only small parts to be protected,
         * consider using a ASharedModule.
         * @param dataStore Containing data required for the execution of the protected module
         * @return a Step that let the ThreadPool know if it can continue to the next module or stop and send a response
         *
         */
        virtual Step safeProcess(DataStore &dataStore) = 0;

        // Deleted Constructors and Operators
    public:
        AProtectedModule(AProtectedModule const &) = delete;
        AProtectedModule(AProtectedModule &&) = delete;
        AProtectedModule &operator=(AProtectedModule const &) = delete;
        AProtectedModule &operator=(AProtectedModule &&) = delete;
    };
}

#endif // EXISTENZIA_ASAFESHAREDMODULE_HPP

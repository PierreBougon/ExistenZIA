//
// Created by duhieub on 11/17/17.
//

#ifndef EXISTENZIA_ASHAREDMODULE_HPP
#define EXISTENZIA_ASHAREDMODULE_HPP

#include "AModule.hpp"
#include "DataStore.hpp"
#include "Step.hpp"

/**
 * \file ASharedModule.hpp
 * \brief This module is shared between threads (thus clients)
 * \author Benjamin.D
 * \version 0.1
 * \date 17 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class ASharedModule ASharedModule.hpp
 *
 */
namespace xzia
{
    class AModuleManager;

    class ASharedModule : public AModule
    {
    public:
        explicit ASharedModule(std::string const &name, AModuleManager &manager);
        virtual ~ASharedModule() = default;

        /**
         *
         * \fn process
         * \brief This method can be called by any module that require an access to it, it passes data through the
         * DataStore class. This Module is NOT thread safe, it is at the developer charge to protect it.
         * @param dataStore
         * @return
         *
         */
        virtual Step process(DataStore &dataStore) = 0;

    protected:
        std::mutex mutex;

        // Deleted Constructors and Operators
    public:
        ASharedModule(ASharedModule const &) = delete;
        ASharedModule(ASharedModule &&) = delete;
        ASharedModule &operator=(ASharedModule const &) = delete;
        ASharedModule &operator=(ASharedModule &&) = delete;
    };
}

#endif //EXISTENZIA_ASHAREDMODULE_HPP

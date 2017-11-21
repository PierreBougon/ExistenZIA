//
// Created by duhieub on 11/17/17.
//

#ifndef EXISTENZIA_ASHAREDMODULE_HPP
#define EXISTENZIA_ASHAREDMODULE_HPP

#include "AModule.hpp"
#include "ADataStore.hpp"
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
    class ASharedModule : public AModule
    {
    public:

        /**
         *
         * \fn process
         * \brief
         * @param dataStore
         * @return
         *
         */
        virtual Step process(ADataStore &dataStore) = 0;
    };
}

#endif //EXISTENZIA_ASHAREDMODULE_HPP

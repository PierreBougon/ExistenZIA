//
// Created by duhieub on 11/17/17.
//

#ifndef EXISTENZIA_ASAFESHAREDMODULE_HPP
#define EXISTENZIA_ASAFESHAREDMODULE_HPP

#include "AModule.hpp"
#include "ADataStore.hpp"
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
    class ASafeSharedModule : public ASharedModule
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
        Step process(ADataStore &dataStore) override;


    protected:
        /**
         *
         * \fn processData
         * \brief
         * @param dataStore
         * @return
         *
         */
        virtual Step safeProcess(ADataStore &dataStore) = 0;

    private:
        std::mutex  mutex;
    };
}

#endif //EXISTENZIA_ASAFESHAREDMODULE_HPP

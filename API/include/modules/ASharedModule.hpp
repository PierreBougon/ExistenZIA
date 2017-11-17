//
// Created by duhieub on 11/17/17.
//

#ifndef EXISTENZIA_ASHAREDMODULE_HPP
#define EXISTENZIA_ASHAREDMODULE_HPP

#include "AModule.hpp"
#include "ADataStore.hpp"
#include "Task.hpp"

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
namespace xzia {
    class ASharedModule : AModule {
    protected:
        std::mutex  mutex;
    public:

        /**
         *
         * \fn process
         * \brief
         * @param dataStore
         * @return
         *
         */
        Step process(ADataStore &dataStore);


         /**
          *
          * \fn processData
          * \brief
          * @param dataStore
          * @return
          *
          */
        Step processData(ADataStore &dataStore);
    };
}

#endif //EXISTENZIA_ASHAREDMODULE_HPP

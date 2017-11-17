//
// Created by duhieub on 11/17/17.
//

#ifndef EXISTENZIA_APROTECTEDMODULE_HPP
#define EXISTENZIA_APROTECTEDMODULE_HPP

#include "AModule.hpp"
#include "ADataStore.hpp"
#include "Task.hpp"

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
namespace xzia {
    class AProtectedModule : AModule {
    private:
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

#endif //EXISTENZIA_APROTECTEDMODULE_HPP

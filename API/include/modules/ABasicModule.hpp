//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ABASICMODULE_HPP
#define EXISTENZIA_ABASICMODULE_HPP

#include "AModule.hpp"
#include "ADataStore.hpp"
#include "Task.hpp"

/**
 * \file ABasicModule.hpp
 * \brief
 * \author Matthieu.S
 * \version 0.1
 * \date 16 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class ABasicModule ABasicModule.hpp ABasicModule.hpp
 *
 */
namespace xzia {
    class ABasicModule : AModule {
    protected:
        ADataStore  dataStore;
    public:

        /**
         *
         * \fn process
         * \brief
         * @param task
         * @return
         *
         */
        Step process(Task &task);

        /**
         *
         * \fn addData
         * \brief
         *
         */
        void addData(data::Data data);
    };
}

#endif //EXISTENZIA_ABASICMODULE_HPP

//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ABASICMODULE_HPP
#define EXISTENZIA_ABASICMODULE_HPP

#include "AModule.hpp"
#include "ADataStore.hpp"
#include "Step.hpp"
#include "task/Task.hpp"

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
namespace xzia
{
    class AHTTPModule : public AModule
    {
    public:

        /**
         *
         * \fn process
         * \brief
         * @param task
         * @return
         *
         */
        virtual Step process(Task &task) = 0;

        /**
         *
         * \fn addData
         * \brief
         *
         */
        virtual void addData(Data data) = 0;

    protected:
        ADataStore  dataStore;
    };
}

#endif //EXISTENZIA_ABASICMODULE_HPP

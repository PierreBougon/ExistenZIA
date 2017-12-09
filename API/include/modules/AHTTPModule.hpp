//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ABASICMODULE_HPP
#define EXISTENZIA_ABASICMODULE_HPP

#include "AModule.hpp"
#include "DataStore.hpp"
#include "Step.hpp"

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
 * \class AHTTPModule AHTTPModule.hpp AHTTPModule.hpp
 *
 */
namespace xzia
{
    class ATask;

    class AHTTPModule : public AModule
    {
    public:
        AHTTPModule(std::string const &name, AModuleManager &manager);

        /**
         *
         * \fn process
         * \brief
         * @param task
         * @return
         *
         */
        virtual Step process(ATask &task) = 0;

        /**
         *
         * \fn addData
         * \brief
         * @param data key
         *
         */
        template <typename T>
        void        addData(T data, std::string const& key)
        {
            dataStore.addData<T>(data, key);
        }

    protected:
        DataStore  dataStore;
    };
}

#endif //EXISTENZIA_ABASICMODULE_HPP

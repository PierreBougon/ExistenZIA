//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ABASICMODULE_HPP
#define EXISTENZIA_ABASICMODULE_HPP

#include "AModule.hpp"
#include "DataStore.hpp"
#include "Step.hpp"

/**
 * \file AHTTPModule.hpp
 * \brief Standard module that is used in the task execution list
 * \author Matthieu.S
 * \version 0.1
 * \date 16 novembre 2017
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
        virtual ~AHTTPModule() = default;

        /**
         * \fn Constructor
         * @param name Module name
         * @param manager Module manager
         */
        explicit AHTTPModule(std::string const &name, AModuleManager &manager);
        AHTTPModule(AHTTPModule const &httpModule);

        /**
         *
         * \fn process
         * \brief This method is called by the workers in the AThreadPool, the logic of the module shall be coded
         * here
         * @param task The Task that is passed through all modules
         * @return a Step that let the ThreadPool know if it can continue to the next module or stop and send a response
         *
         */
        virtual Step process(ATask &task) = 0;

        /**
         *
         * \fn addData
         * \brief Allows to add data to a module for future use in the Task execution list. Store important data
         * in the store of the module
         */
        template <typename T>
        void        addData(std::string const& key, T data)
        {
            dataStore.addData<T>(key, data);
        }

    protected:
        DataStore  dataStore;
    };
}

#endif //EXISTENZIA_ABASICMODULE_HPP

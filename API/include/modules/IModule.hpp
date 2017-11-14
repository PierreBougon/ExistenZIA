//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IMODULE_HPP
#define EXISTENZIA_IMODULE_HPP

#include <iostream>
#include <memory>

/**
 * \file IModule.hpp
 * \brief
 * \author Matthieu.S
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class IMessage IMessage.hpp IMessage.hpp
 * \class ATask ATask.hpp ATask.hpp
 * \class ILoader ILoader.hpp ILoader.hpp
 * \class IModuleFactory IModuleFactory.hpp IModulueFactory.hpp
 * \class IModule IModule.hpp IModule.hpp
 */
namespace xzia {
    enum Step;
    class IMessage;
    class ATask;
    class ILoader;
    class IModuleFactory;

    class IModule {
    public:

        /**
         *
         * \fn process
         * \brief
         * @param req Request received
         * @param res Response received
         * @param task Current task
         * @return Return the state after processing the task
         *
         */
        virtual xzia::Step process(IMessage &req, IMessage &res, ATask &task) = 0;

        /**
         *
         * \fn process
         * \brief
         * @return Return the state after processing
         *
         */
        virtual xzia::Step process() = 0;

        /**
         *
         * \fn clone
         * \brief
         * @return Return an unique_ptr copy instance of the current IModule
         *
         */
        virtual std::unique_ptr<IModule> clone() = 0;

        /**
         *
         * \fn config
         * \brief
         * @param loader //TODO Describe this param here
         * @param moduleFactory //TODO Describe this param here
         *
         */
        virtual void config(ILoader &loader, IModuleFactory &moduleFactory) = 0;
    };
}

#endif //EXISTENZIA_IMODULE_HPP

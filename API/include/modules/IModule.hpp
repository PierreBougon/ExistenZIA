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
        * \fn processHTTP
        * \brief This function is called on the execution list,
        * it will automatically call the right process method
        *
        * @param req Request received
        * @param res Response to send to client
        * @param task Current task
        * @return Return the state after processing the task
        *
        */
        virtual xzia::Step process(IMessage &req, IMessage &res, ATask &task) = 0;

        /**
         *
         * \fn clone
         * \brief Return a clone of this module which is useful for models in the ModuleFactory
         * @return Return an unique_ptr copy instance of the current IModule
         *
         */
        virtual std::unique_ptr<IModule> clone() = 0;

        /**
         *
         * \fn config
         * \brief Tell the module te refresh itself its configuration from loader
         * @param loader reference to a loader to be able to get his own module config
         * @param moduleFactory reference to module factory to change module model
         *
         */
        virtual void config(ILoader &loader, IModuleFactory &moduleFactory) = 0;

    protected:
        /**
        *
        * \fn processHTTP
        * \brief This function is called by process,
        * you have to implement module logic here for any HTTPModule
        *
        * @param req Request received
        * @param res Response to send to client
        * @param task Current task
        * @return Return the state after processing the task
        *
        */
        virtual xzia::Step processHTTP(IMessage &req, IMessage &res, ATask &task) = 0;

        /**
         *
         * \fn processBasic
         * \brief This function is called by process,
         * you have to implement module logic here for any BasicModule
         *
         * @return Return the state after processing
         *
         */
        virtual xzia::Step processBasic() = 0;
    };
}

#endif //EXISTENZIA_IMODULE_HPP

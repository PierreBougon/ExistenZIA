//
// Created by Pierre Bougon on 13/11/17.
//

#ifndef ZIA_ITASK_HPP_
#define ZIA_ITASK_HPP_

#include <memory>
#include <vector>
#include "modules/Step.hpp"
#include "modules/AHTTPModule.hpp"

/**
 * \file ITask.hpp
 * \brief The ITask Interface manage the communication between request and client.
 * It also links all the different module specific to the request.
 * \author Pierre.B
 * \version 0.2
 * \date 10 December 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class ITask ITask.hpp ITask.hpp
 *
 */
namespace xzia
{
    class ITask
    {
    public:
        virtual ~ITask() = default;

        /**
        *
        * \fn clone
        * \brief Clone the current task
        * @return Return a pointer of a clone from the current task.
        *
        */
        virtual std::unique_ptr<ITask>                      clone() const = 0;

        /**
        *
        * \fn getExecutionList
        * \brief Get the current list of module
        * @return Return a vector containing the modules
        *
        */
        virtual std::vector<std::unique_ptr<AHTTPModule>>   &getExecutionList() = 0;

        /**
        *
        * \fn getRequest
        * \brief Get the current Request
        * @return Return a reference on the the current Request
        *
        */
        virtual Request const                               &getRequest() const = 0;

        /**
        *
        * \fn getResponse
        * \brief Get the current Response
        * @return Return a reference on the current Response
        *
        */
        virtual Response                                    &getResponse() = 0;

        /**
        *
        * \fn getClient
        * \brief Get the current client
        * @return Return the current Client id
        *
        */
        virtual Client const                                &getClient() const = 0;

        /**
        *
        * \fn getModulePosition
        * \brief Get a module at a specific position with the module passed in parameter
        * @param module Reference of the module we want to get
        * @return Return the position of the module asked in parameter in the module list
        *
        */
        virtual size_t                                      getModulePosition(AHTTPModule const &module) const = 0;

        /**
         * \fn getNextModule
         * \brief Execution list module getter
         * @param moduleName Module name
         * @return A reference to the next module searched
         */
        virtual AHTTPModule                                 &getNextModule(std::string const &moduleName) const = 0;

        /**
        *
        * \fn pushModuleNext
        * \brief Push a module in the module list after the current Position
        * @param module Module which going to be set in the module list
        *
        */
        virtual void                                        pushModuleNext(std::unique_ptr<AHTTPModule> module) = 0;

        /**
        *
        * \fn pushModuleBack
        * \brief Push a module at the end of the module list
        * @param module Module which going to be set in the module list
        *
        */
        virtual void                                        pushModuleBack(std::unique_ptr<AHTTPModule> module) = 0;

        /**
        *
        * \fn pushModuleAtPosition
        * \brief Push a module int the module at a specific position
        * @param module Module which going to be set in the module list
        * @param pos Position where the module is going to be set
        *
        */
        virtual void                                        pushModuleAtPosition(std::unique_ptr<AHTTPModule> module, size_t pos) = 0;
    };
}

#endif // !ZIA_ITASK_HPP_

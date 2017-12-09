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
 * \brief
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

        /**
        *
        * \fn clone
        * \brief
        * @return
        *
        */
        virtual std::unique_ptr<ITask>                      clone() const = 0;

        /**
        *
        * \fn getExecutionList
        * \brief
        * @return
        *
        */
        virtual std::vector<std::unique_ptr<AHTTPModule>>   &getExecutionList() = 0;

        /**
        *
        * \fn getRequest
        * \brief
        * @return
        *
        */
        virtual Request const                               &getRequest() const = 0;

        /**
        *
        * \fn getResponse
        * \brief
        * @return
        *
        */
        virtual Response                                    &getResponse() = 0;

        /**
        *
        * \fn getClient
        * \brief
        * @return
        *
        */
        virtual Client const                                &getClient() const = 0;

        /**
        *
        * \fn getModulePosition
        * \brief
        * @param module
        *
        */
        virtual size_t                                      getModulePosition(AHTTPModule const &module) const = 0;

        /**
        *
        * \fn pushModuleNext
        * \brief
        * @param module
        *
        */
        virtual void                                        pushModuleNext(std::unique_ptr<AHTTPModule> module) = 0;

        /**
        *
        * \fn pushModuleBack
        * \brief
        * @param module
        *
        */
        virtual void                                        pushModuleBack(std::unique_ptr<AHTTPModule> module) = 0;

        /**
        *
        * \fn pushModuleAtPosition
        * \brief
        * @param module pos
        *
        */
        virtual void                                        pushModuleAtPosition(std::unique_ptr<AHTTPModule> module, size_t pos) = 0;
    };
}

#endif // !ZIA_ITASK_HPP_

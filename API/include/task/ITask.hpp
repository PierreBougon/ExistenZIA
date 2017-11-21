//
// Created by Pierre Bougon on 13/11/17.
//

#ifndef ZIA_ITASK_HPP_
#define ZIA_ITASK_HPP_

#include <memory>
#include <vector>
#include "modules/Step.hpp"

namespace xzia
{
    class ITask
    {
    public:
        virtual std::unique_ptr<ITask>                      clone() const = 0;
        virtual std::vector<std::unique_ptr<AHTTPModule>>   &getExecutionList() = 0;
        virtual Request const                               &getRequest() const = 0;
        virtual Response                                    &getResponse() = 0;
        virtual Client const                                &getClient() const = 0;
        virtual size_t                                      getModulePosition(AHTTPModule const &module) const = 0;
        virtual void                                        pushModuleNext(std::unique_ptr<AHTTPModule> module) = 0;
        virtual void                                        pushModuleBack(std::unique_ptr<AHTTPModule> module) = 0;
        virtual void                                        pushModuleAtPosition(std::unique_ptr<AHTTPModule> module, size_t pos) = 0;
    };
}

#endif // !ZIA_ITASK_HPP_

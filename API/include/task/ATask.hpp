//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ATASK_HPP
#define EXISTENZIA_ATASK_HPP

#include <string>
#include <vector>
#include "sza/api/http.h"
#include "modules/AHTTPModule.hpp"
#include "modules/Step.hpp"
#include "ITask.hpp"

/**
 * \file ATask.hpp
 * \brief ATask represent the module list defined by the Request passed in the Constructor
 * \author Robin.U
 * \version 0.2
 * \date 10 December 2017
 * \namespace xzia
 * \class ATask ATask.hpp ATask.hpp
 *
 */
namespace xzia
{
    class ATask : public ITask
    {
    public:
        ATask() = delete;
        ATask(std::unique_ptr<zia::api::HttpDuplex> req,
              std::vector<std::unique_ptr<AHTTPModule>> executionList);

        virtual ~ATask() = default;

    protected:
        std::unique_ptr<zia::api::HttpDuplex> req;
        std::vector<std::unique_ptr<AHTTPModule>>   executionList;
    };
}

#endif //EXISTENZIA_ATASK_HPP

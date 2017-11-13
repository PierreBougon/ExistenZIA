//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ATASK_HPP
#define EXISTENZIA_ATASK_HPP

#include <string>
#include <vector>
#include "modules/IModule.hpp"
#include "ITask.hpp"
#include "tools/UID.hpp"

namespace xzia
{
    class ATask : ITask
    {
        std::string name;
        std::string method;
        std::string resource;
        xzia::uid   uid;
        std::vector<std::unique_ptr<IModule>> executionList;
    };
}

#endif //EXISTENZIA_ATASK_HPP

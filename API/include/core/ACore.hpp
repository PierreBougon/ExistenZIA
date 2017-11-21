//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ACORE_HPP
#define EXISTENZIA_ACORE_HPP

#include <vector>
#include <thread/AThreadPool.hpp>
#include "modules/AModuleManager.hpp"
#include "loader/ILoader.hpp"
#include "client/Client.hpp"
#include "ICore.hpp"

namespace xzia
{
    class ACore : public ICore
    {
    public:
        /**
         *
         * \fn ACore
         * \brief Constructor of the class ACore. We set a configuration representing by a string
         * @param config Configuration of the core
         *
         */
        ACore(std::string config);

    protected:
        ILoader                 &loader;
        AModuleManager          modules;
        AThreadPool             threadPool;
        std::vector<Client>     cli;
    };
}

#endif //EXISTENZIA_ACORE_HPP

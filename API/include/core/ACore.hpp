//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ACORE_HPP
#define EXISTENZIA_ACORE_HPP

#include <vector>
#include "task/ATaskFactory.hpp"
#include "task/ITaskFactory.hpp"
#include "thread/AThreadPool.hpp"
#include "network/INetwork.hpp"
#include "modules/AModuleManager.hpp"
#include "loader/ILoader.hpp"
#include "ICore.hpp"

/**
 * \file ACore.hpp
 * \brief Kernel of the API, ACore is the class linking all other classes
 * \author Edouard.P
 * \version 0.1
 * \date 17 novembre 2017
 * \namespace xzia
 * \struct ACore ACore.hpp ACore.hpp
 */
namespace xzia
{
    class ACore : public ICore
    {
    public:
        virtual ~ACore() = default;
        /**
         *
         * \fn ACore
         * \brief Constructor of the class ACore.
         * @param config Configuration file path
         *
         */
        explicit ACore(std::string const &config);

    protected:
        std::unique_ptr<ILoader>            loader;
        std::unique_ptr<AModuleManager>     moduleManager;
        std::unique_ptr<AThreadPool>        threadPool;
        std::unique_ptr<INetwork>           network;
        std::unique_ptr<ATaskFactory>       taskFactory;
        std::string                         configFile;
    };
}

#endif //EXISTENZIA_ACORE_HPP

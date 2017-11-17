//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ACORE_HPP
#define EXISTENZIA_ACORE_HPP

#include <vector>
#include "AModuleManager.hpp"
#include "ILoader.hpp"
#include "AThreadManager.hpp"
#include "Client.hpp"


/**
 * \file ACore.hpp
 * \brief
 * \author Pierre.B
 * \version 0.1
 * \date 17 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class ACore ACore.hpp ACore.hpp
 */
namespace xzia {
    class ACore {
    public:

        /**
         *
         * \fn ACore
         * \brief Constructor of the class ACore. We set a configuration representing by a string
         * @param config Configuration of the core
         *
         */
        ACore(std::string config);

        /**
         *
         * \fn run
         * \brief
         *
         */
        void run();

    protected:
        ILoader                 &loader;
        AModuleManager          modules;
        AThreadManager          manager;
        std::vector<Client>     cli;
    };
}

#endif //EXISTENZIA_ACORE_HPP

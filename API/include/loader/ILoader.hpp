//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ILOADER_HPP
#define EXISTENZIA_ILOADER_HPP

#include <iostream>
#include <map>
#include <vector>

/**
 * \file ILoader.hpp
 * \brief
 * \author Edouard.P
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class ILoader ILoader.hpp ILoader.hpp
 *
 */
namespace xzia
{
    class ILoader
    {
    public:
        /**
         *
         * \fn reload
         * \brief This method allows the loader to reload the configuration, updating the list of available modules,
         * and their corresponding configuration
         *
         */
        virtual void reload() = 0;
    };
}
#endif //EXISTENZIA_ILOADER_HPP

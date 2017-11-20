//
// Created by duhieub on 11/16/17.
//

#ifndef EXISTENZIA_ALOADER_HPP
#define EXISTENZIA_ALOADER_HPP

#include "ILoader.hpp"
#include "IConfigLoader.hpp"
#include "IDLLLoader.hpp"

/**
 * \file ALoader.hpp
 * \brief
 * \author Edouard.P
 * \version 0.1
 * \date 16 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class ALoader ALoader.hpp ALoader.hpp
 *
 */
namespace xzia
{
    class ALoader : ILoader
    {
    private:
        IConfigLoader   config;
        IDLLLoader      dll;
    };
}

#endif //EXISTENZIA_ALOADER_HPP

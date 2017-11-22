/**
 * \file ALoader.hpp
 * \brief
 * \author Edouard.P
 * \version 0.1
 * \date 16 novembre 2017
 *
 */

#ifndef EXISTENZIA_ALOADER_HPP
#define EXISTENZIA_ALOADER_HPP

#include <bits/unique_ptr.h>
#include "ILoader.hpp"
#include "IConfigLoader.hpp"
#include "IDLLLoader.hpp"

/**
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
        std::unique_ptr<IConfigLoader>   config;
        std::unique_ptr<IDLLLoader>      dll;
    };
}

#endif //EXISTENZIA_ALOADER_HPP

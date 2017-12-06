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

#include <memory>
#include "ILoader.hpp"
#include "IConfigLoader.hpp"
#include "IDLLLoader.hpp"

/**
 * \brief ALoader manages the dynamic loading of the modules and the configuration of those
 * according to the configuration loader
 *
 * \namespace xzia
 * \class ALoader
 *
 */
namespace xzia
{
    class ALoader : ILoader
    {
    private:
        std::unique_ptr<IDLLLoader>      dllLoader;
        std::unique_ptr<IConfigLoader>   configLoader;
    };
}

#endif //EXISTENZIA_ALOADER_HPP

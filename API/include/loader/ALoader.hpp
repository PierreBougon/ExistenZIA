#ifndef EXISTENZIA_ALOADER_HPP
#define EXISTENZIA_ALOADER_HPP

#include <memory>
#include "ILoader.hpp"
#include "IConfigLoader.hpp"
#include "IDLLLoader.hpp"

/**
 * \file ALoader.hpp
 * \author Edouard.P
 * \brief ALoader manages the dynamic loading of the modules and the configuration of those
 * according to the configuration loader
 * \version 0.1
 * \date 16 novembre 2017
 *
 * \namespace xzia
 * \class ALoader ALoader.hpp ALoader.hpp
 *
 */
namespace xzia
{
    class ALoader : ILoader
    {
    protected:
        std::unique_ptr<IDLLLoader>      dllLoader;
        std::unique_ptr<IConfigLoader>   configLoader;
    };
}

#endif //EXISTENZIA_ALOADER_HPP

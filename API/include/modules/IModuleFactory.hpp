//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IMODULEFACTORY_HPP
#define EXISTENZIA_IMODULEFACTORY_HPP

#include <iostream>
#include <memory>

/**
 * \file IModuleFactory.hpp
 * \brief
 * \author Benjamin.D
 * \version 0.1
 * \date 13 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class IModule IModule.hpp IModule.hpp
 * \class IModuleFactory IModuleFactory.hpp IModuleFactory.hpp
 */
namespace xzia {
    class IModule;

    class IModuleFactory {
    public:

        /**
         *
         * \fn add
         * \brief
         * @param name //TODO Describe this param here
         */
        virtual void add(std::string const &name) = 0;

        /**
         * \fn remove
         * \brief
         * @param name //TODO Describe this param here
         */
        virtual void remove(std::string const &name) = 0;

        /**
         *
         * \fn getInstance
         * \brief
         * @param name //TODO Describe this param here
         * @return Return an unique_ptr IModule of the specific Instance
         */
        virtual std::unique_ptr<IModule> getInstance(std::string const &name) const = 0;
    };
}

#endif //EXISTENZIA_IMODULEFACTORY_HPP

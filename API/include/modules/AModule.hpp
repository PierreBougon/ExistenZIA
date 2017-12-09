//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_AMODULE_HPP
#define EXISTENZIA_AMODULE_HPP

#include <mutex>
#include <memory>
#include "DataStore.hpp"

/**
 * \file AModule.hpp
 * \brief
 * \author Robin.U
 * \version 0.1
 * \date 17 novembre 2017
 *
 * add comment here
 *
 * \namespace xzia
 * \class AModule AModule.hpp AModule.hpp
 *
 */
namespace xzia
{
    class AModuleManager;

    class AModule
    {

        /**
         * \enum Type
         */
        enum class Type : unsigned char
        {
            Http = 0,
            Shared,
            SelfProtect
        };

    public:
        /**
         * \fn AModule
         * \brief Default constructor deleted
         */
        AModule() = delete;

        /**
         * \fn AModule
         * \brief Constructor of AModule where we set the name of the module
         * @param name Name of the module
         */
        AModule(std::string const &name, AModuleManager &moduleManager);

/*
         *
         * \fn getType
         * \brief Get the type of the module
         * @return Return the type of the module
         *
         *//*

        Type getType() const;
*/

        /**
         *
         * \fn getName
         * \brief Get the name of the module
         * @return Return the name of the module
         *
         */
        const std::string &getName() const;

    protected:
        AModuleManager  &moduleManager;
        Type            type;


    private:
        std::string name;
    };
}
#endif //EXISTENZIA_AMODULE_HPP

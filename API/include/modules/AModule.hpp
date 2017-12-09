//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_AMODULE_HPP
#define EXISTENZIA_AMODULE_HPP

#include <mutex>
#include <memory>
#include "DataStore.hpp"

/**
 * @file
 * \brief This is the most basic module, you should *never* directly inherit from this class, use the other
 * module Abstract Classes : AHTTPModule, ASharedModule and AProtectedModule
 * \author Robin.U
 * \version 0.1
 * \date 17 novembre 2017
 * \namespace xzia
 * \class AModule AModule.hpp AModule.hpp
 *
 */
namespace xzia
{
    class AModuleManager;

    class AModule
    {
    public:
        /**
         * \enum Type of the module
         */
        enum class Type : unsigned char
        {
            HTTP = 0,
            SHARED,
            PROTECTED
        };

        /**
         * \fn AModule
         * \brief Default constructor deleted
         */
        AModule() = delete;

        /**
         * \fn AModule
         * \brief Constructor of AModule
         * @param name Module name
         * @param moduleManager allows the module to access shared modules
         * or modify the task execution list
         * @param type Module type
         */
        AModule(std::string const &name, AModuleManager &moduleManager, AModule::Type type);

        /**
         *
         * \fn getType
         * \brief Get the module type
         * @return Return the module type
         *
         */
        Type getType() const;

        /**
         *
         * \fn getName
         * \brief Get the module name
         * @return Return the module name
         *
         */
        const std::string &getName() const;

    protected:
        AModuleManager  &moduleManager;
        Type            type;

    private:
        std::string name;
        friend class AHTTPModule;
        friend class ASharedModule;
        virtual ~AModule() = 0;
    };
}
#endif //EXISTENZIA_AMODULE_HPP

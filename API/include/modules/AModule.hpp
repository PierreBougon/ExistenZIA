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

        virtual ~AModule() = default;

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

        /**
         * \fn setVersion
         * \brief Set the version of the module, used by the Loader to know when it can close a loaded library
         * \param version value
         */
        void setVersion(std::uint32_t version);

        /**
         * \fn getVersion
         * \brief version getter
         * @return the module version
         */
        std::uint32_t getVersion() const;

    protected:
        std::string     name;
        AModuleManager  &moduleManager;
        Type            type;
        std::uint32_t   version;

    private:
        friend class AHTTPModule;
        friend class ASharedModule;
    };
}
#endif //EXISTENZIA_AMODULE_HPP

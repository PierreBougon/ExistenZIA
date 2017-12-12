//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_AMODULE_HPP
# define EXISTENZIA_AMODULE_HPP

# include <mutex>
# include <memory>

# ifdef _WIN32
#  include <windows.h>
# endif

# include "DataStore.hpp"

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
         * \fn AModule
         * \brief Default constructor deleted
         */
        AModule() = delete;

        virtual ~AModule();

        /**
         * \fn AModule
         * \brief Constructor of AModule
         * @param name Module name
         * @param moduleManager allows the module to access shared modules
         * or modify the task execution list
         * @param type Module type
         */
        AModule(std::string const &name, AModuleManager &moduleManager);

        /**
         *
         * \fn getName
         * \brief Get the module name
         * @return Return the module name
         *
         */
        const std::string &getName() const;

        /**
        * \fn configure
        * \brief The module configure itself using the map passed as parameter. This map is generated
        * from the JSON configuration file
        * @param config map containing all the necessary configuration elements
        */
        virtual void configure(std::map<std::string, std::string> const &config) = 0;

        /**
         * \fn setHandle
         * \brief This function sets the handle loaded from the config loader. this handle is autmatically closed
         * inside the AModule destructor
         * @param dlHandle handle to set
         */
        #ifdef __linux__
            void setHandle(void *dlHandle);
        #elif _WIN32
            void setHandle(HINSTANCE dlHandle);
        #endif

    protected:
        std::string     name;
        AModuleManager  &moduleManager;

    private:
        #ifdef __linux__
            void *dlHandle;
        #elif _WIN32
            HINSTANCE dlHandle;
        #endif
        friend class AHTTPModule;
        friend class ASharedModule;
    };
}
#endif //EXISTENZIA_AMODULE_HPP

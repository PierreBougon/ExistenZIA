//
// Created by duhieub on 11/16/17.
//

#ifndef EXISTENZIA_AMODULEMANAGER_HPP
#define EXISTENZIA_AMODULEMANAGER_HPP

#include <mutex>
#include "IModuleManager.hpp"

/**
 * \file AModuleManager.hpp
 * \brief The module manager has ownership of all modules and is responsible for reloading them.
 * It creates copies of basic modules and pass references to shared ones.
 * \author Marc.B
 * \version 0.2
 * \date 10 December 2017
 * \namespace xzia
 * \class AModuleManager AModuleManager.hpp AModuleManager.hpp
 *
 */
namespace xzia
{
    class ALoader;
    class ASharedModule;
    class AHTTPModule;

    class AModuleManager : public IModuleManager
    {
    public:

        /**
         *
         * \fn AModuleManager
         * \brief Constructor of the class AModuleManager
         * @param load Set the loader in the class
         *
         */
        explicit AModuleManager(ALoader &load);
        virtual ~AModuleManager() = default;


    private:
        std::mutex                                      reloadMutex;
        std::vector<std::unique_ptr<ASharedModule>>     sharedModules;
        std::vector<std::unique_ptr<AHTTPModule>>       httpModules;
        ALoader                                         &loader;
   };

}
#endif //EXISTENZIA_AMODULEMANAGER_HPP

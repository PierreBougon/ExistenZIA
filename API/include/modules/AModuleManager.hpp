//
// Created by duhieub on 11/16/17.
//

#ifndef EXISTENZIA_AMODULEMANAGER_HPP
#define EXISTENZIA_AMODULEMANAGER_HPP

#include <mutex>
#include "IModuleManager.hpp"

namespace xzia
{
    class ALoader;
    class AModule;
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
    AModuleManager(ALoader &load);

    private:
        std::mutex                      reloadMutex;
        std::vector<ASharedModule>      sharedModules;
        std::vector<AHTTPModule>        httpModules;
        ALoader                         &loader;
   };

}
#endif //EXISTENZIA_AMODULEMANAGER_HPP

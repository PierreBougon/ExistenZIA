//
// Created by duhieub on 11/16/17.
//

#ifndef EXISTENZIA_AMODULEMANAGER_HPP
#define EXISTENZIA_AMODULEMANAGER_HPP

#include <vector>
#include <mutex>

namespace xzia {

    class ALoader;
    class AModule;
    class ABasicModule;
    class AModuleManager {
    private:
        std::mutex              reloadMutex;
        std::vector<AModule>    modules;
        ALoader                 &loader;

    public:

        /**
         *
         * \fn AModuleManager
         * \brief Constructor of the class AModuleManager
         * @param load Set the loader in the class
         *
         */
        AModuleManager(ALoader &load);

        /**
         *
         * \fn getSharedModule
         * \brief
         * @param module
         * @return
         *
         */
        AModule &getSharedModule(std::string module);

        /**
         *
         * \fn getBasicModule
         * \brief
         * @param module
         * @return
         *
         */
        std::unique_ptr<ABasicModule> getBasicModule(std::string module);

        /**
         *
         * \fn reload
         * \brief
         *
         */
        void reload();

        /**
         *
         * \fn getTaskModules
         * \brief
         * @return
         *
         */
        std::vector<ABasicModule> getTaskModules();
   };
}
#endif //EXISTENZIA_AMODULEMANAGER_HPP

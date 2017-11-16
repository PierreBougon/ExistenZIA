//
// Created by duhieub on 11/16/17.
//

#ifndef EXISTENZIA_MODULEMANAGER_HPP
#define EXISTENZIA_MODULEMANAGER_HPP

#include <mutex>
#include "AModule.hpp"
#include "AHTTPModule.hpp"

namespace xzia {

    class ModuleManager {
    private:
        std::mutex reloadMutex;
        std::vector<AModule> modules;

    public:
        AModule &getSharedModule(std::string module);
        std::unique_ptr<AHTTPModule> getHTTPModule(std::string module);
        void reload();
        std::vector<AHTTPModule> getTaskModules();
   };
}
#endif //EXISTENZIA_MODULEMANAGER_HPP

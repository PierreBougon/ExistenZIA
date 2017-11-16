//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_AMODULE_HPP
#define EXISTENZIA_AMODULE_HPP

#include <mutex>
#include <memory>
#include "IModule.hpp"
#include "ADataStore.hpp"
#include "ModuleManager.hpp"

namespace xzia {
    class AModule : IModule {

        enum class Type : unsigned char
        {
            http = 0,
            shared,
            selfProtect
        };

    public:
        AModule() = delete;
        AModule(AModule::Type moduleType, std::string const &name, std::mutex &mutex);

    private:
        Step process(IMessage &req, IMessage &res, ATask &task) override final;

    protected:
        data::ADataStore dataStore;

    private:
        Type        type;
        bool        threaded;
        std::mutex  &mutex;
        std::string name;
        ModuleManager &moduleManager;
    };
}
#endif //EXISTENZIA_AMODULE_HPP

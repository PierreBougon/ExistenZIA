//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_AMODULE_HPP
#define EXISTENZIA_AMODULE_HPP

#include <mutex>
#include <memory>
#include "IModule.hpp"
#include "ADataStore.hpp"
#include "AModuleManager.hpp"

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

    public:
        Type getType() const;

        const std::string &getName() const;

    protected:
        AModuleManager  &moduleManager;

    private:
        Type        type;
        std::string name;
    };
}
#endif //EXISTENZIA_AMODULE_HPP

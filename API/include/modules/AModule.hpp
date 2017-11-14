//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_AMODULE_HPP
#define EXISTENZIA_AMODULE_HPP

#include <mutex>
#include <memory>
#include "IModule.hpp"
#include "ADataStore.hpp"

namespace xzia
{

    class AModule : IModule
    {
        enum class Type : unsigned char
        {
            basic = 0,
            http
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
    };
}
#endif //EXISTENZIA_AMODULE_HPP

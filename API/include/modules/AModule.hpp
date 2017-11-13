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

    protected:
        data::ADataStore dataStore;

    private:
        bool        threaded;
        std::mutex  mutex;
        std::string name;

    public:
        AModule();
        AModule(std::string const &name, std::mutex *mutex = nullptr);

        void config(ILoader &loader, IModuleFactory &factory) override;
        std::unique_ptr<IModule> clone() override;
    };
}
#endif //EXISTENZIA_AMODULE_HPP

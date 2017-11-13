//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_AMODULE_HPP
#define EXISTENZIA_AMODULE_HPP

#include <mutex>
#include <memory>
#include "IModule.hpp"
#include "ADataStore.hpp"

namespace xzia {

    class AModule : IModule {

    protected:
        ADataScore dataScore;

    private:
        bool threated;
        std::mutex mutex;
        std::string name;

    public:
        AModule();

        AModule(std::string const &name, std::mutex *mutex = nullptr);

        xzia::Step process(IMessage &message, IMessage &iMessage, ATask &task) override = 0;


        std::unique_ptr<IModule> clone() override;

        void config(ILoader &loader, IModuleFactory &factory) override;
    };
}
#endif //EXISTENZIA_AMODULE_HPP

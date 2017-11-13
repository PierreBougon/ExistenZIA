//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_AMODULEFACTORY_HPP
#define EXISTENZIA_AMODULEFACTORY_HPP

#include <vector>
#include <map>
#include <mutex>
#include <memory>
#include "IModuleFactory.hpp"
#include "AModule.hpp"

namespace xzia {
    class AModuleFactory : IModuleFactory {
    protected:
        std::vector<AModule> modules;

    public:
        std::map<std::string, std::mutex> mutexMap;

        void add(std::string const &string) override;

        void remove(std::string const &string) override;

        std::unique_ptr<IModule> getInstance(std::string const &string) override;
    };
}
#endif //EXISTENZIA_AMODULEFACTORY_HPP

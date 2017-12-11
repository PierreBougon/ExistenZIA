//
// Created by 53818 on 11/12/2017.
//

#ifndef EXISTENZIA_BASIMODULE_HPP
#define EXISTENZIA_BASIMODULE_HPP

#include "modules/AHTTPModule.hpp"

namespace xzia {
    class BasicModule : public AHTTPModule {
    public:
        BasicModule(std::string const &name, AModuleManager &moduleManager);
        Step process(ATask &task) override;

    private:
        int do_some_operation(Message const &message);
    };
}

#endif //EXISTENZIA_BASIMODULE_HPP

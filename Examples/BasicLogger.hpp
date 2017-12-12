//
// Created by 53818 on 11/12/2017.
//

#ifndef EXISTENZIA_BASICLOGGER_HPP
#define EXISTENZIA_BASICLOGGER_HPP

#include "modules/ASharedModule.hpp"

namespace xzia {
    class BasicLogger : public ASharedModule {
    public:
        BasicLogger(const std::string &name, AModuleManager &manager);

        Step process(DataStore &dataStore) override;
    };
}

#endif //EXISTENZIA_BASICLOGGER_HPP

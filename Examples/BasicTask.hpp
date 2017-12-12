#ifndef EXISTENZIA_BASICTASK_HPP
#define EXISTENZIA_BASICTASK_HPP

#include "task/ATask.hpp"

namespace xzia {
    class BasicTask : ATask {

        std::vector<std::unique_ptr<AHTTPModule>> &getExecutionList() override;
        const Request &getRequest() const override;
        Response &getResponse() override;
        const Client &getClient() const override;
        AHTTPModule &getNextModule(std::string const &moduleName) const override;
        void pushModuleNext(std::unique_ptr<AHTTPModule> module) override;
        Step processModules() override;
        void pushModuleBack(std::unique_ptr<AHTTPModule> module) override;
    };
}

#endif //EXISTENZIA_BASICTASK_HPP

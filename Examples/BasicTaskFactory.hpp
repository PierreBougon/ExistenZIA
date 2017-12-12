#ifndef EXISTENZIA_BASICTASKFACTORY_HPP
#define EXISTENZIA_BASICTASKFACTORY_HPP

#include "task/ATaskFactory.hpp"

namespace xzia {
    class BasicTaskFactory : public ATaskFactory {
        std::unique_ptr<ATask> createTask(std::unique_ptr<Request> req, Client client) override;
    };
}

#endif //EXISTENZIA_BASICTASKFACTORY_HPP

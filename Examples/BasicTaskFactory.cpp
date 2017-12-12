#include "modules/AModuleManager.hpp"
#include "BasicTaskFactory.hpp"
#include "BasicTask.hpp"

std::unique_ptr<xzia::ATask> xzia::BasicTaskFactory::createTask(std::unique_ptr<xzia::Request> req, xzia::Client client) {
    return (std::make_unique<xzia::BasicTask>(req, client, moduleManager.getExecutionListModel()));
}

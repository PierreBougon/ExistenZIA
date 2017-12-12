#include "BasicTask.hpp"

std::unique_ptr<xzia::ITask> xzia::BasicTask::clone() const {
    // TODO implement a method that deep clone a task
    return nullptr;
}

std::vector<std::unique_ptr<xzia::AHTTPModule>> &xzia::BasicTask::getExecutionList() {
    return executionList;
}

const xzia::Request &xzia::BasicTask::getRequest() const {
    return *req.get();
}

xzia::Response &xzia::BasicTask::getResponse() {
    return res;
}

const xzia::Client &xzia::BasicTask::getClient() const {
    return client;
}

xzia::AHTTPModule &xzia::BasicTask::getNextModule(std::string const &moduleName) const {
    // TODO implement a real method that get the current next module
    return *executionList.front();
}

void xzia::BasicTask::pushModuleNext(std::unique_ptr<xzia::AHTTPModule> module) {
    // TODO implement a real method that really push a module to the next position
    executionList.push_back(module);
}

void xzia::BasicTask::pushModuleBack(std::unique_ptr<xzia::AHTTPModule> module) {
    executionList.push_back(module);
}

// Using a while loop here because iterators might cause errors since the execution list can be modified
xzia::Step xzia::BasicTask::processModules() {
    int position = 0;
    Step step = Step::Continue;

    while (step == Step::Continue || position < executionList.size()) {
        step = (*executionList[position]).process(*this);
        ++position;
    }
    return step;
}

//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_ITASKPOOL_HPP
#define EXISTENZIA_ITASKPOOL_HPP

#include <iostream>
#include <vector>

namespace xzia {
    class ATask;
    class ITaskPool {
    public:
        virtual void addModel(std::string const &model, std::string const &ressource,
                              std::vector<std::string> &moduleNames) = 0;
        virtual void deleteModel(std::string const &name) = 0;
        virtual ATask &getTask(std::string const &name) const = 0;
        virtual void deleteTask(int id) = 0;
    };
}

#endif //EXISTENZIA_ITASKPOOL_HPP

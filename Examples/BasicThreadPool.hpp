//
// Created by 53818 on 13/12/2017.
//

#ifndef EXISTENZIA_BASICTHREADPOOL_HPP
#define EXISTENZIA_BASICTHREADPOOL_HPP

#include "thread/AThreadPool.hpp"

namespace xzia {
    class BasicThreadPool : public AThreadPool {
    public:
        ~BasicThreadPool() override;

        void addTask(std::unique_ptr<ATask> task) override;

        std::vector<std::unique_ptr<ATask>> getAllTaskDone() override;

    protected:
        void threadWorkflow(unsigned int id) override;
    };
}

#endif //EXISTENZIA_BASICTHREADPOOL_HPP

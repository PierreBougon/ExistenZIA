#include "BasicThreadPool.hpp"

void xzia::BasicThreadPool::addTask(std::unique_ptr<xzia::ATask> task) {
    mutex.lock();
    todoTasks.push(std::move(task));
    mutex.unlock();
    condvar.notify_one();
}

std::vector<std::unique_ptr<xzia::ATask>> xzia::BasicThreadPool::getAllTaskDone() {
    std::vector<std::unique_ptr<xzia::ATask>> out;

    mutex.lock();
    while (!doneTasks.empty()) {
        out.push_back(std::move(doneTasks.front()));
        doneTasks.pop();
    }
    mutex.unlock();
    return out;
}

void xzia::BasicThreadPool::threadWorkflow(unsigned int id)
{
    while (running)
    {
        // Check if we have done all the tasks to do
        mutex.lock();
        if (todoTasks.empty()) {
            // Wait until we rcv notification
            mutex.unlock();
            std::unique_lock<std::mutex> ulock(mutex);
            condvar.wait(ulock);
        } else {
            mutex.unlock();
        }

        // If ThreadPool is down we stop the thread
        if (!running)
            break;

        mutex.lock();
        if (todoTasks.empty()) {
            mutex.unlock();
            continue;
        }
        std::unique_ptr<xzia::ATask> task = std::move(todoTasks.front());
        todoTasks.pop();
        mutex.unlock();

        // Process the task
        (*task).processModules();

        // Add task to doneTasks queue
        mutex.lock();
        doneTasks.push(std::move(task));
        mutex.unlock();
    }
}

xzia::BasicThreadPool::~BasicThreadPool()
{
    bool hasAllThreadJoined = false;
    condvar.notify_all();

    while (!hasAllThreadJoined) {
        hasAllThreadJoined = true;
        for (std::thread &th : threads) {
            if (th.joinable()) {
                th.join();
            } else {
                hasAllThreadJoined = false;
            }
        }
    }
    threads.clear();
}

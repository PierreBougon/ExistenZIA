#include "BasicCore.hpp"

xzia::BasicCore::BasicCore(const std::string &config) :
        ACore(config)
{
    // TODO initialize unique pointers with actual classes
}

std::string userInput() {
    // TODO implement a way to actually get user input
    return ("");
}

void xzia::BasicCore::run()
{
    bool running = true;

    (*network).start();
    while (running)
    {
        std::string input = userInput();

        if (!input.empty())
        {
            if (input == "stop")
            {
                running = false;
            }
            else if (input == "reload")
            {
                (*loader).reload();
            }
        }

        if (running)
        {
            std::vector<std::unique_ptr<Request>> requests = (*network).getAllRequests();
            while (!requests.empty())
            {
                (*threadPool).addTask((*taskFactory).createTask(requests.back(), (*requests.back()).client));
                requests.pop_back();
            }

            std::vector<std::unique_ptr<ATask>> tasksDone = (*threadPool).getAllTaskDone();
            while (!tasksDone.empty())
            {
                (*network).sendResponse((*tasksDone.back()).getResponse());
                tasksDone.pop_back();
            }

            (*loader).notifyVersionsOutOfUse((*threadPool).getVersionsOutOfUse());
        }
    }
}

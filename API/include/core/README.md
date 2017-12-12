# The Core
## [ICore]
[ICore] is the interface that ensure a core is runnable through the `run()` method.
The inheriting class shall code the logic that runs **everything** in this method.

The core is basically an **infinite** loop that connects every components to each other and makes the HTTP server actually do its job. 

## [ACore]
Since the implementation of a [ICore] should be common to everyone, we provide you an abstract implementation to spare you some time: [ACore].

It has a unique pointer to all the components and take a path to the configuration file so it can configure itself through the loader

The following code snippet shows a basic implementation of the [ICore] run method :
```cpp
void xzia::BasicCore::run()
{
    bool running = true;

    network->start();
    while (running)
    {
        std::string input = userInput();

        if (!input.empty()) // 1
        {
            if (input == "stop")
            {
                running = false;
            }
            else if (input == "reload")
            {
                loader->reload();
            }
        }

        if (running) 
        {
            std::vector<std::unique_ptr<Request>> requests = network->getAllRequests(); // 2
            while (!requests.empty()) 
            {
                threadPool->addTask(taskFactory->createTask(requests.back(), requests.back()->client)); // 3
                requests.pop_back();
            }

            std::vector<std::unique_ptr<ATask>> tasksDone = threadPool->getAllTaskDone(); // 4
            while (!tasksDone.empty())
            {
                network->sendResponse(tasksDone.back()->getResponse()); // 5
                tasksDone.pop_back();
            }

            loader->notifyVersionsOutOfUse(threadPool->getVersionsOutOfUse()); // 6
        }
    }
}
```
1. Checking if the user wants to stop or reload the [ALoader]
2. Getting all received [Request] from the [INetwork]
3. Creating a [ATask] using the [ATaskFactory] for each [Request] and pushing it into the [AThreadPool] 
4. Getting all [ATask] done processing
5. Sending each [Response] back to the client
6. Notifying the [ALoader] the versions that are not used anymore in the [AThreadPool]

[ATaskFactory]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/task/ATaskFactory.hpp
[ATask]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/task/ATask.hpp
[INetwork]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/network/INetwork.hpp
[Response]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/http/Response.hpp
[Request]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/http/Request.hpp
[ALoader]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/loader/ALoader.hpp
[AThreadPool]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/thread/AThreadPool.hpp
[ICore]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/core/ICore.hpp
[ACore]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/core/ACore.hpp
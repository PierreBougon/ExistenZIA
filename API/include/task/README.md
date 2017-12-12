# Structuring the modules processing
## The Task
When processing modules, you need order : which modules to execute firsts ? How to add a module ?
Which module is the last ?

To answer those questions we came with an object : the Task.


### [ITask](Task)

### [ATask]

## The TaskFactory

### [ITaskFactory]

### [ATaskFactory]

[Loader]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/loader
[config.json]: https://github.com/PierreBougon/ExistenZIA/blob/master/Examples/config.json
[AModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AModule.hpp
[AHTTPModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AHTTPModule.hpp
[ASharedModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/ASharedModule.hpp
[AProtectedModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AProtectedModule.hpp
[ModuleManager]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AModuleManager.hpp
[Task]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/task/ITask.hpp
[ATask]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/task/ATask.hpp
[ITaskFactory]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/task/ITaskFactory.hpp
[ATaskFactory]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/task/ATaskFactory.hpp
[Response]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/http/Response.hpp
[DataStore]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/DataStore.hpp
[Step]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/Step.hpp
[basic logger]: https://github.com/PierreBougon/ExistenZIA/blob/master/Examples/BasicModule.cpp
[basic example]: https://github.com/PierreBougon/ExistenZIA/blob/master/Examples/BasicModule.cpp
# The ThreadPool
## [IThreadPool]
[IThreadPool] is the interface that ensure `Workers` are waiting for tasks to be proceed.
The inheriting class shall code the following methods :

- ```virtual void addTask(std::unique_ptr<ATask> task) = 0;``` : add a task to the 
waiting 
queue of tasks todo
- ```virtual std::vector<std::unique_ptr<ATask>> getAllTaskDone() = 0;``` : get tasks 
from the done queue, threadPool ensure that these tasks have been proceed

The ThreadPool is basically a wrapper to communicate with the pool of thread without 
even thinking about threads. The only thing you have to do is to give a `task todo` and
 get a `task done`. 

## [AThreadPool]
Since the implementation of a [IThreadPool] should be common to everyone, we provide you
 an abstract implementation to spare you some time: [AThreadPool].

###Thread loop
```cpp 
virtual void threadWorkflow(unsigned int id) = 0;
```
This is the infinite loop for the thread. You have to wait to have some work to do, get
 a task from the todo queue and then proceed it. Finally you add this task to the done 
 queue to let the core get this task.


[AThreadPool]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/thread/AThreadPool.hpp
[IThreadPool]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/thread/IThreadPool.hpp

# The ThreadPool
## [IThreadPool]
[IThreadPool] is the interface that ensure that **workers** -- or threads -- are waiting for tasks to be proceeded.
The inheriting class shall implement the following methods :

* **Adding** a task to the todo tasks queue.
```cpp
virtual void addTask(std::unique_ptr<ATask> task) = 0;
```
* **Getting** tasks done processing from the thread pool.
```
virtual std::vector<std::unique_ptr<ATask>> getAllTaskDone() = 0;
```

The thread pool is basically a wrapper to communicate with the pool of threads without 
even thinking about them. The only thing you have to do is to give a **task todo** and
 get a **task done**. 

## [AThreadPool]
Since the implementation of a [IThreadPool] should be common to everyone, we provide you
 an abstract implementation to spare you some time: [AThreadPool].

###Thread loop
```cpp 
virtual void threadWorkflow(unsigned int id) = 0;
```
This is the infinite loop for the thread. The workers wait to have some work to do, get
 a task from the todo queue and then proceed it. Finally you add this back task when its done processing to the done queue to let the core get this task.

We provide you a basic implementation of this class as an [example].

[AThreadPool]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/thread/AThreadPool.hpp
[IThreadPool]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/thread/IThreadPool.hpp
[example]: https://github.com/PierreBougon/ExistenZIA/blob/master/Examples/BasicThreadPool.hpp

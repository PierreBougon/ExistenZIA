# The Core
## [ICore]
[ICore] is the interface that ensure a core is runnable through the `run()` method.
The inheriting class shall code the logic that runs **everything** in this method.

The core is basically an **infinite** loop that connects every components to each other and makes the HTTP server actually do its job. 

## [ACore]
Since the implementation of a [ICore] should be common to everyone, we provide you an abstract implementation to spare you some time: [ACore].

It has a unique pointer to all the components and take a path to the configuration file so it can configure itself through the loader

The following code snippet shows a basic implementation of the [ICore] run method :
```

```

[ICore]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/core/ICore.hpp
[ACore]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/core/ACore.hpp
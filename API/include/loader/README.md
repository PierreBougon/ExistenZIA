# Loading Files and Modules
## The Configuration file
### Why JSON ?
We selected JSON as our configuration file representation because it is a simple, easily readable and editable format. It cover most of our needs to configure a http server and modules.

The Configuration file provided is an example, **you are free to modify it or do something totally different**.
We just present you an example of how we, at ExistenZia, would do it.

### The Core object

The following snippet shows a non-exhaustive [Core] configuration from the file [config.json]  
```json
{
  "core": {
    "threads" : 4,
    "max_clients" : 1500,
    "port" : 5312
  }
}
```

While most properties are self-explanatory and can be dispensed, you should always have a way to reconfigure your core without restarting it, instead of using default values.
 
### The execution list

It is the execution list model that will copied to each [Task] and which every request will be going through.
```json
{
   "executionList" : [
      "cypher",
      "boringModuleName",
      "lameModule",
      "cypher"
    ]
}
```

Each of the modules in the execution list references a module object in the "modules" JSON object array described below.

### The Module Array Object
The following snippet is a basic representation of the module JSON object array :  
```json
{
  "modules" : [{
    "name" : "boringModuleName",
    "location" : "./",
    "type" : "http"
   }, {
    "name" : "logger",
    "location" : "./",
    "type" : "shared",
    "config" : {
      "level" : "debug",
      "file" : "./logs/log.out",
      "console" : true
    }
  }]
}
```
Two modules are described here, a [AHTTPModule] named `boringModuleName` with no specific configuration and a [ASharedModule] named `logger` with a configuration specification.

**Those names will be used as references by the [ModuleManager] when searching for modules.**

The `location` property is the relative or absolute path to the library.
Since you'll be implementing the [IConfigLoader] and the [ALoader] you are free to decide how to load those libraries, using entry points configured the JSON file or using the same entry point for all libraries, use what suits **you** best.

The `config` object serves as an additional configuration fields for the module that can be provided to let it configure itself. 
A `std::map<std::string, std::string>` will be generated from it and passed to the [AModule] configure method. 

## [IConfigLoader]
This interface ensure that we can load each important and required configuration parts from the [config.json] file :
* the core configuration
* the execution list
* the configuration of each module

## [ALoader]
Vocabulary :
   * library : a dynamically loaded library and stored in memory
   * module : an instantiation of that library used by the HTTP server

The [ALoader] load libraries, configure and return a handle to them as [AModule] unique pointer. **Only one version of that unique pointer should be stored in the [ModuleManager].** 

When calling the `reload()` method, the [ALoader] shall creates new handles for
the modified libraries, and replace the modules in the [ModuleManager].

The [ALoader] shall keep track of the library version and increment them as they are reloaded.

**But beware for [AHTTPModules](AHTTPModule)** ! It shall conserve the old library loaded and not close them until either one of the following situations arise :
* the method `reload` has been called and a module version that is no more used has been notified through the `versionOutOfUse` method
* the [ALoader] is destroyed

For the [ASharedModules](ASharedModule) it shall **block** the access to them using a **mutex**, and replace them.
 
 Otherwise you might encounter some memory errors when old version modules are still running in the [ThreadPool].

[ThreadPool]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/thread/AThreadPool.hpp
[IConfigLoader]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/loader/IConfigLoader.hpp
[ALoader]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/loader/ALoader.hpp
[AModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AModuleManager.hpp
[ModuleManager]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AModuleManager.hpp
[AHTTPModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/AHTTPModule.hpp
[ASharedModule]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/modules/ASharedModule.hpp
[Core]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/core/ACore.hpp
[Task]: https://github.com/PierreBougon/ExistenZIA/blob/master/API/include/task/ATask.hpp
[config.json]: https://github.com/PierreBougon/ExistenZIA/blob/master/example/config.json

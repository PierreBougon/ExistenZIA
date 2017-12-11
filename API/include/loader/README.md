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
    "port" : 5312,
    "executionList" : [
      "cypher",
      "boringModuleName",
      "lameModule",
      "cypher"
    ]
  }
}
```

While most properties are self-explanatory and can be dispensed, the property `executionList` is mandatory : it is the execution list model that will copied to each [Task] and you need a way to configure and represent it.

Each of the module in the execution list references a module object in the "modules" JSON object array described below.

### The Module Object
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

The `config` object serves as an additional configuration field for the module that can be provided to let it configure itself 

[IConfigLoader]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/loader/IConfigLoader.hpp
[ALoader]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/loader/ALoader.hpp
[ModuleManager]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/modules/AModuleManager.hpp
[AHTTPModule]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/modules/AHTTPModule.hpp
[ASharedModule]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/modules/ASharedModule.hpp
[Core]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/core/ACore.hpp
[Task]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/API/include/task/ATask.hpp
[config.json]: https://github.com/PierreBougon/ExistenZIA/blob/Loader_documentation/example/config.json

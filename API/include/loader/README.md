# Loading Files and Modules
## Configuration file
### Why JSON ?
We selected JSON as our configuration file representation because it is a simple, easily readable and editable format. It cover most of our needs to configure a http server and modules

### The Core object

The following snippet shows a non-exhaustive core configuration  
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

While most properties are self-explanatory, the property `executionList` is mandatory : it is the [Task]

[Task]:(https://link)
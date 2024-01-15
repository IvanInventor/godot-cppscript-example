# godot-cppscript-example

Example project, modified version of godot-cpp test project using godot-cppscript macros.

[Keywords description](https://github.com/IvanInventor/godot-cppscript-example/blob/master/src/example.hpp) (read comments)

[Property hints description](https://github.com/IvanInventor/godot-cppscript-example/blob/master/src/example_properties.hpp) (read comments)

## Quick setup guide
- Install [dependencies](https://github.com/IvanInventor/godot-cpp-script#dependencies)
- Clone repository
```bash
git clone https://github.com/IvanInventor/godot-cppscript-example --recurse-submodules
```
- Checkout your version of godot
    - For stable releases: checkout one of [tags](https://github.com/godotengine/godot-cpp/tags)
    ```bash
    cd godot-cppscript-example/godot-cpp/
    git checkout <tag>
    ```
    - For custom builds (from [guide](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html#building-the-c-bindings)):
    ```bash
    # switch to branch corresponding to godot version
    # Godot 4.1.3 -> 4.1
    cd godot-cppscript-example/godot-cpp/
    git pull origin 4.1
    git switch 4.1
    # Generate custom bindings
    ./your_godot_executable --dump-extension-api
    mv extension_api.json gdextension/extension_api.json
    ```
- Build library
  - For scons
  ```bash
  cd ../
  scons
  ```
    - For Cmake
  ```bash
  cd ../
  cmake -Bbuild
  cmake --build build
  ```
- Open project in editor
- Run scene
- Check console for test results

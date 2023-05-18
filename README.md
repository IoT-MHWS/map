# cws-map
Coworking space map

## Install dependencies

Create conan profile

```bash
conan profile detect
```

Install dependencies

```bash
conan install . --output-folder=build --build=missing
```

## Generate cmake


```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=debug -DGRPC_SERVER=y
```

* `GRPC_SERVER` - whether compile grpc-server
* `FETCH_GRPC` - fetch gRPC library and compile using it or use installed (recommended be `True` because of dependencies that can be not present)
* `PROTO_LOC` - location of proto module, relative to current `CMakeLists.txt` or absolute (default set for current repo structure)

Others:

* `APP` - whether compile app (for tests)


### Possible values for variables

* True: `y`, non-zero digit
* False: `n`, `0`
* Default: False

## Building

```
cmake --build build
```

## TODO

* [x] Refresh how to write in c++
* [ ] Learn c++20 and multithreading (long journey)

### Might

* [ ] Add spdlog for the project
* [ ] Replace `std::mutex` with atomic read-modify-write

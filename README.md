# Pascal

This version of Pascal is based on book [Writing Compilers and Interpreters: A Software Engineering Approach](https://www.amazon.com/Writing-Compilers-Interpreters-Software-Engineering/dp/0470177071) also this project is a work in progress and my first attempt to learn about compilers.

## Build

To build manually Pascal run:

```bash
$ mkdir build
$ git submodule init && git submodule update
$ cd build
$ cmake ..
$ make && make install
$ cd ..
$ bin/pascal examples/hello.pas -x
```

## Status

  - ✔ lexer
  - ✔ parser

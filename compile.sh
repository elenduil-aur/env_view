#!/bin/bash
# Build project script.

# Run clean target.
if [ "$1" == "-clean" ]; then
  rm -rf build
  exit 0
fi
let threads=`cat /proc/cpuinfo | grep processor | wc -l`

[ ! -d build ] && mkdir -p build/

# Build debug version if such parameter is specified.
if [ "$1" == "-debug" ]; then
  [ ! -d build/debug ] && mkdir build/debug
  cd build/debug
  qmake ../../ && make -j$threads
  exit 0
fi

# Build release binary version.
[ ! -d build/release ] && mkdir build/release
cd build/release
qmake ../../ && make -j$threads

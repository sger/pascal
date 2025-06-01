#!/bin/bash

set -e

BUILD_DIR="build"

echo "🛠️  Configuring project (if needed)..."
cmake -B $BUILD_DIR -S . -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE=$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake

echo "🔨 Building project..."
cmake --build $BUILD_DIR

echo "🧪 Running tests..."
cd $BUILD_DIR
ctest --output-on-failure

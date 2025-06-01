#!/bin/bash

set -e

BUILD_DIR="build"

echo "🔄 Cleaning build directory..."
rm -rf $BUILD_DIR
mkdir -p $BUILD_DIR
cd $BUILD_DIR

echo "🔧 Configuring with CMake and clang-tidy..."
cmake -G Ninja ..

echo "🚀 Building with Ninja..."
ninja

echo "✅ Build finished. Running executable:"
./pascal

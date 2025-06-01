#!/bin/bash

set -e

BUILD_DIR="build"

# Allow overriding VCPKG_ROOT via environment variable
VCPKG_ROOT=${VCPKG_ROOT:-"$HOME/vcpkg"}
TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"

echo "🔄 Cleaning build directory..."
rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

echo "🔧 Configuring with CMake and clang-tidy..."
cmake -G Ninja .. \
  -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE"

echo "🚀 Building with Ninja..."
ninja

echo "✅ Build finished. Running executable:"
./pascal

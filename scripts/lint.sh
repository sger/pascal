#!/bin/bash

set -e

# Compiler flags
FLAGS="-Iinclude -std=c++17"

# Find all .cpp files and run clang-tidy on each
echo "🔍 Running clang-tidy on source files..."

find src include -name '*.cpp' | while read file; do
    echo "👉 Linting $file"
    clang-tidy "$file" -- ${FLAGS}
done

echo "✅ clang-tidy completed."

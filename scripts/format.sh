#!/bin/bash

set -e

echo "🧼 Running clang-format on all source and header files..."

find src include -name '*.[ch]pp' | while read file; do
    echo "✨ Formatting $file"
    clang-format -i "$file"
done

echo "✅ Formatting complete."

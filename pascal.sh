#!/bin/bash

set -e

case "$1" in
  build)
    ./scripts/build.sh
    ;;
  test)
    ./scripts/run_tests.sh
    ;;
  format)
    ./scripts/format.sh
    ;;
  lint)
    ./scripts/lint.sh
    ;;
  help|--help|-h|"")
    echo "Usage: ./pascal.sh [command]"
    echo "Commands:"
    echo "  build     Build the project"
    echo "  test      Run tests"
    echo "  format    Format source code"
    echo "  lint      Run clang-tidy"
    ;;
  *)
    echo "Unknown command: $1"
    exit 1
    ;;
esac

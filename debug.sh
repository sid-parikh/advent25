#!/usr/bin/env bash

set -euo pipefail

# Configure in Debug mode
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug > /dev/null

# Build the project
cmake --build build-debug > /dev/null

# Run the program
./build-debug/day"$1"
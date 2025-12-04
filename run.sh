#!/usr/bin/env bash

set -euo pipefail

cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON > /dev/null
cmake --build build > /dev/null
./build/day"$1"
#!/usr/bin/env bash
export MAKEFLAGS="-j 8"
mkdir -p bin
cd bin
cmake ../src
make

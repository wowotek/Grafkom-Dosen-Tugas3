#!/bin/bash

CC=g++
CFLAGS=-W -Wall -Wextra -Wpedantic -g -O3

clear
echo "CLERING BINARIES..."
rm -f bin/*
rm -rf bin/
sleep 0.5
mkdir bin/
echo "COMPILING..."
$CC $CFLAGS -o bin/main.exec src/main.cpp -lGL -lGLU -lglut
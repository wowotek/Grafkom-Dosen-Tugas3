#!/bin/bash

CC=g++
CFLAGS=-W -Wall -Wextra -Wpedantic -g -O3

clear
echo "CLERING BINARIES..."
rm -f bin/*
sleep 0.2
rm -rf bin/
sleep 0.2
mkdir bin/
sleep 0.2
echo "COMPILING..."
$CC $CFLAGS -o bin/main.exec src/main.cpp -lGL -lGLU -lglut
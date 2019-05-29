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
echo "-------------------"
echo ""
echo "COMPILING..."
$CC $CFLAGS -o bin/main.o -c src/main.cpp
$CC $CFLAGS -o bin/main.exec bin/main.o -lGL -lGLU -lglut

echo "------------"
echo ""
echo "Running..."
echo "--- PROGRAM START ---"
echo ""
timeout 10 ./bin/main.exec
echo "---- PROGRAM END ----"
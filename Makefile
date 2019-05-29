CC := g++

CFLAGS := -W -Wall -Wextra -Wpedantic -g -O3
LDFLAGS := -lGL -lGLU -lglut

BIN_DIR := ./bin
OBJ_DIR := ${BIN_DIR}/o
OBJECTS := ${OBJ_DIR}/main.o

SRC_DIR := ./src

EXE := ${BIN_DIR}/main


all: ${EXE}

.PHONY: clean

clean:
	rm -rf ${OBJECTS} ${EXE}

${EXE}: ${OBJECTS}; ${CC} $(CFLAGS) $^ -o $@ $(LDFLAGS)

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp; ${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}:; $(shell mkdir ${BIN_DIR})
${OBJ_DIR}:${BIN_DIR}; $(shell mkdir ${OBJ_DIR})

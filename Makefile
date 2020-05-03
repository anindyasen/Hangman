# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# the build target executable:
MODULE = hangman

#path of binary
BIN_PATH = $(PWD)/bin
SRC_PATH = $(PWD)


# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall $(INCLUDES)

#object files are part of the final program
SOURCES     := $(shell find $(SRC_PATH) -type f -name "*.c")
OBJECTS     := $(patsubst $(SRC_PATH)/%,$(BIN_PATH)/%,$(SOURCES:.c=.o))


# define any directories containing header files other than /usr/include
INCLUDES = -Iinclude/

all: $(BIN_PATH) $(MODULE)

$(MODULE): $(OBJECTS)
	$(CC) -o $(BIN_PATH)/$@ $^ $(CFLAGS)
	@echo "Build Successful"

$(BIN_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -r $(BIN_PATH)

$(BIN_PATH):
	mkdir -p $(BIN_PATH)

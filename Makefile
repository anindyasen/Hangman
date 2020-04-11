# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# the build target executable:
MODULE = hangman

#path of binary
BIN_PATH = ./bin


# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall $(INCLUDES)

#object files are part of the final program
OBJECTS = hash.o \
		  hangman.o


# define any directories containing header files other than /usr/include
INCLUDES = -Iinclude/

all: $(MODULE)

$(MODULE): $(OBJECTS)
	$(CC) -o $(BIN_PATH)/$@ $^ $(CFLAGS)
#	$(CC) $(CFLAGS) $(INCLUDES) -o $(BIN_PATH)/$(MODULE) $(OBJ)

clean:
	$(RM) $(BIN_PATH)/$(MODULE)
	$(RM) *.o

$(shell   mkdir -p $(BIN_PATH))

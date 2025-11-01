# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

# Source files
SRC = src/main.c 

# Object files
OBJ = $(SRC:.c=.o)

# Output binary
TARGET = shell

# Default build
all: $(TARGET)

# Link object files to create the binary
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

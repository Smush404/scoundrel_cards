# Makefile for a basic ASCII-text card game in C

# Compiler and flags
CC     = gcc
CFLAGS = -Wall -Wextra -std=c17

# Project files
SRC    = scoundrel.c
OBJ    = $(SRC:.c=.o)
TARGET = cardgame

# Default rule
all: $(TARGET)

# Link the program
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

# Rebuild from scratch
rebuild: clean all
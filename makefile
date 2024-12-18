# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Target executable
TARGET = dracarys

# Source and Object Files
SRCS = main.c Character.c Player.c Key.c Item.c Room.c
OBJS = $(SRCS:.c=.o)

# Header Files
HEADERS = Character.h Player.h Key.h Item.h Room.h

# Default target
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compiling source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Force rebuild
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild

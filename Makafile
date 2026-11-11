# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Target executable name
TARGET = student_system

# Source files and corresponding object files
SRCS = main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_persistence.c stud_sort.c
OBJS = $(SRCS:.c=.o)
HDRS = student.h

# Default rule: builds the executable
all: $(TARGET)

# Link all object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each .c file into a .o object file
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the compiled program
run: all
	./$(TARGET)

# Clean up compiled binaries and object files
clean:
	rm -f $(OBJS) $(TARGET) $(TARGET).exe

# Clean build files AND delete the saved binary database
distclean: clean
	rm -f student.dat

.PHONY: all run clean distclean

# Source files
SOURCES := hello.c
# Object files
OBJECTS := hello.o
# Name of the archive for the distribution
ARCHIVE := Hello

# main target
all: HelloWorld

# to build object-file hello.o, hello.c is needed
hello.o: hello.c

# compile files and build executable
# $^ = inputs
# $@ = name of the target
HelloWorld: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

# build distribution
dist:
	tar -zcf $(ARCHIVE).tar.gz $(SOURCES) Makefile

# Delete all files that were created by building the program
clean:
	$(RM) $(OBJECTS) $(ARCHIVE).tar.gz HelloWorld

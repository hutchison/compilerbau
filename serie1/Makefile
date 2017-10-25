# Source files
SOURCES := main.c
# Object files
OBJECTS := moco.o

all: moco

moco.o: main.c
	$(CC) -c -o $@ $^

# compile files and build executable
# $^ = inputs
# $@ = name of the target
moco: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	$(RM) $(OBJECTS) moco

# Source files
SOURCES := diagnosis.c buffer.c scanner.c tokens.c main.c
# Object files
OBJECTS := diagnosis.o buffer.o scanner.o tokens.o moco.o

CFLAGS = -Wall

all: moco

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

moco.o: main.c
	$(CC) -c $(CFLAGS) -o $@ $^

# compile files and build executable
# $^ = inputs
# $@ = name of the target
moco: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	$(RM) $(OBJECTS) moco

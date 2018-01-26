.PHONY: clean

OBJECTS := main.o scanner.o parser.o diagnosis.o symboltable.o

all: moco

moco: $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

scanner.cc: scanner.l parser.h
	flex scanner.l

scanner.h: scanner.cc

parser.cc: parser.y
	bison parser.y

parser.h: parser.cc

main.cc: diagnosis.h scanner.h parser.h symboltable.h

diagnosis.cc: diagnosis.h scanner.h

symboltable.cc: symboltable.h scanner.h diagnosis.h levenshtein.h

clean:
	$(RM) $(OBJECTS) scanner.cc scanner.h parser.cc parser.h moco

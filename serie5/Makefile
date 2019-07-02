.PHONY: clean

OBJECTS := main.o scanner.o parser.o diagnosis.o symboltable.o

all: moco

############

KCFILES = abstract.k unparse.k
KCFLAGS = --no-csgio --yystype --suffix=cc
KCDUMMY = .timestamp
KCSYSTEM = unpk.cc unpk.h k.cc k.h rk.cc rk.h yystype.h $(KCFILES:.k=.cc) $(KCFILES:.k=.h)

$(KCSYSTEM): $(KCDUMMY)

$(KCDUMMY): $(KCFILES)
	touch $@
	kc++ $(KCFLAGS) $^
	gsed -i 's/reinterpret_cast<int>/reinterpret_cast<size_t>/g' k.cc
	gsed -i 's/include <string>/include <cstring>/g' k.cc

OBJECTS += rk.o k.o unpk.o $(KCFILES:.k=.o)

KCCLEANFILES = $(KCDUMMY) $(KCSYSTEM)

############


moco: $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

scanner.cc: scanner.l parser.h
	flex scanner.l

scanner.h: scanner.cc

parser.cc: parser.y $(KCDUMMY)
	bison parser.y

parser.h: parser.cc

main.cc: diagnosis.h scanner.h parser.h symboltable.h

diagnosis.cc: diagnosis.h scanner.h

symboltable.cc: symboltable.h scanner.h diagnosis.h levenshtein.h

clean:
	$(RM) $(OBJECTS) $(KCCLEANFILES) scanner.cc scanner.h parser.cc parser.h moco

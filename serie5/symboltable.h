#pragma once

#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <string>
#include "parser.h"

class Identifier;

typedef enum {
    VARIABLE, CONSTANT, TYPE, PROCEDURE, MODULE
} identifer_t;

class SymbolTable {
    public:
        static void pushScope();
        static void popScope();
        static void define(std::string, identifer_t, YYLTYPE);
        static void use(std::string, YYLTYPE);
        static std::string best_match;

    private:
        static SymbolTable* currentScope;
        static std::set<std::string> names;

        SymbolTable* parent;
        std::map<std::string, Identifier*> table;
        void _define(std::string, identifer_t, YYLTYPE);
        void _use(std::string, YYLTYPE);
};


class Identifier {
    public:
        static std::vector<Identifier*> identifiers;
        static void print(FILE *);

        std::string name;
        identifer_t type;
        YYLTYPE location;

        std::vector<YYLTYPE> used;

        Identifier(std::string, identifer_t, YYLTYPE);
};

/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KEY_ARRAY = 258,
    KEY_BEGIN = 259,
    KEY_CHAR = 260,
    KEY_CONST = 261,
    KEY_DO = 262,
    KEY_ELSE = 263,
    KEY_ELSIF = 264,
    KEY_END = 265,
    KEY_FOR = 266,
    KEY_IF = 267,
    KEY_INTEGER = 268,
    KEY_MODULE = 269,
    KEY_OF = 270,
    KEY_PROCEDURE = 271,
    KEY_REAL = 272,
    KEY_REPEAT = 273,
    KEY_RETURN = 274,
    KEY_THEN = 275,
    KEY_TO = 276,
    KEY_TYPE = 277,
    KEY_UNTIL = 278,
    KEY_VAR = 279,
    KEY_WHILE = 280,
    ASSIGN = 281,
    OR = 282,
    AND = 283,
    EQ = 284,
    NE = 285,
    LE = 286,
    GE = 287,
    LEQ = 288,
    GEQ = 289,
    PLUS = 290,
    MINUS = 291,
    ASTERISK = 292,
    SLASH = 293,
    DIV = 294,
    MOD = 295,
    NOT = 296,
    SEMICOLON = 297,
    PERIOD = 298,
    COLON = 299,
    COMMA = 300,
    LPAREN = 301,
    RPAREN = 302,
    LBRACK = 303,
    RBRACK = 304,
    RANGE = 305,
    C_STRING = 306,
    C_CHAR = 307,
    IDENT = 308,
    C_INTEGER = 309,
    C_REAL = 310
  };
#endif

/* Value type.  */

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

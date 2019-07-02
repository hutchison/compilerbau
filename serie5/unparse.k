%uview C;

Module(a, Block(b, c)) -> [C:
  "/* compiled from module \"" a "\" */ \n\n"
  "/* global declarations */\n"
  b
  "\n/* main program */\n"
  "int main() {\n"
  c
  "}"
];

ConstantDeclaration(a, b) -> [C:
  "#define " a " " b "\n"
];

TypeDeclaration(a, b) -> [C:
  "typedef " b " " a ";\n"
];

VariableDeclaration(a, TypeArray(b, c)) -> [C: c " " a "[" b "];"];

VariableDeclaration(a,b) -> [C:
  b " " a ";\n"
];

Procedure(a,b,c,Block(d,e)) -> [C:
  "\n"
  c " " a "(" b ") {\n"
  "/* " a "'s local declarations */\n"
  d
  "\n/* code */\n"
  e
  "}\n\n"
];

Consparameter_list(a, Nilparameter_list()) -> [C: a];
Consparameter_list(a, b=Consparameter_list(*,*)) -> [C: a ", " b];

Parameter(a,b) -> [C: b " " a ];

IndexedVariableDesignator(a, b) -> [C: a "[" b "]"];

TypeIdent(a)    -> [C: a];
TypeInteger()   -> [C: "int"];
TypeReal()      -> [C: "float"];
TypeChar()      -> [C: "char"];
TypeArray(a, b) -> [C: b "[" a "]"];

Subrange(a, b) -> [C: b "-" a];

Assignment(a, b) -> [C:
  a " = " b
];

FunctionCall(a, b) -> [C:
 a "(" b ")"  
];

Return(a) -> [C: "return " a ];

If(a,b,c,d) -> [C:
  "if (" a ") {\n" b
  "} "
  c
  d
];

Elsif(a, b) -> [C: "else if (" a ") {\n" b "} "];

Else(a) -> [C: "else {\n" a "}"];

While(a,b) -> [C: "while (" a ") {\n " b " \n}"];

Repeat(a,b) -> [C: "do {\n" a "\n} while (!" b ")"];

For(a, b, c, d) -> [C: "for (" a " = " b "; " a " != " c "; " a " = " a " +1) {\n " d " \n}"];

Consexpression_list(a, Nilexpression_list()) -> [C: a];
Consexpression_list(a, b=Consexpression_list(*,*)) -> [C: a ", " b];

Consstatement_sequence(a, Nilstatement_sequence()) -> [C: a ";\n"];
Consstatement_sequence(a, b=Consstatement_sequence(*,*)) -> [C: a ";\n" b];

Not(a)        -> [C: "!" a];
Eq(a,b)       -> [C: "(" a " == " b ")"];
Ne(a,b)       -> [C: "(" a " != " b ")"];
Le(a,b)       -> [C: "(" a " < " b ")"];
Ge(a,b)       -> [C: "(" a " > " b ")"];
Leq(a,b)      -> [C: "(" a " <= " b ")"];
Geq(a,b)      -> [C: "(" a " >= " b ")"];
Plus(a,b)     -> [C: "(" a " + " b ")"];
Minus(a,b)    -> [C: "(" a " - " b ")"];
Or(a,b)       -> [C: "(" a " || " b ")"];
Asterisk(a,b) -> [C: "(" a " * " b ")"];
Slash(a,b)    -> [C: "(" a " / " b ")"];
Div(a,b)      -> [C: "(" a " / " b ")"];
Mod(a,b)      -> [C: "(" a " % " b ")"];
And(a,b)      -> [C: "(" a " && " b ")"];

CharConstant(a) -> [C: "'" a "'"];
StringConstant(a) -> [C: "\"" a "\""];

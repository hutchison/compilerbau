(*
    Unser beliebtes Hello World-Programm
*)

MODULE HelloWorld;

TYPE
    myInt = INTEGER;

CONST
    pi = 3.141592653589793238462643383279502884197169399375105820974944;

VAR
    x : REAL;
    y : myInt;
    z : CHAR;

BEGIN
    y := 2;
    x := y * pi;
END HelloWorld.

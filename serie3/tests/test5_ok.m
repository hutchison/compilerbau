(*
	Unser geliebtes Hello World-Programm.
*)

MODULE HelloWorld;

TYPE
	myInt = INTEGER;

CONST
	pi = 3.141592653589793238462643383279502884197169399375105820974944;

VAR
	x : REAL;

BEGIN

	x := (2 + pi);
	x := NOT pi + 3 + x;

END HelloWorld.

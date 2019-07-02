MODULE full;

CONST
    pi = 3.14159;
    two = 2;

TYPE
    GANZZAHL = INTEGER;

VAR
    x : GANZZAHL;
    arr : ARRAY[0 .. 9] OF GANZZAHL;
	f : REAL;

PROCEDURE flaeche(VAR durchmesser : REAL) : REAL;
VAR
    radius : REAL;
BEGIN
	radius := (durchmesser / two);
    RETURN radius * radius * pi;
END flaeche;

BEGIN
    FOR x := 0 TO 9 DO
        arr[x] := 2 * x;
    END;

	f := flaeche(10.0);

	x := 9;
	WHILE x # 0 DO
		arr[x] := arr[x] - 1;
		IF arr[x] > 5
			THEN x := x - 5;
			ELSIF arr[x] < 3
				THEN arr[x] := 10;
			ELSE arr[x] := 0;
		END
	END
END full.
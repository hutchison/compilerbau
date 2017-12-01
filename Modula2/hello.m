MODULE HelloWorld;

TYPE
	myInt = INTEGER;

CONST
	pi = 3.1415926;

VAR
	x : INTEGER;
	s: STRING;
	c :CHAR;
	d:CHAR;
	arr:ARRAY[0..15]OF INTEGER;

BEGIN
	f := 2 + pi;
	x := 13;
	s := "Ich bin ein langer String!";
	c1 := 'a';
	c2:= 'b';
	c3 :='c';
	c4:='d';
	IF x = 13 THEN
		f := f + x;
	ELSE
		x := x + 1;
	END;
	IF x<=15 THEN
		x := x - 1;
	END;
END
HelloWorld.

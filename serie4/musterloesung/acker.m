MODULE ackermann;

VAR
    x : INTEGER;
    a : INTEGER;
    b : INTEGER;

PROCEDURE acker(VAR x : INTEGER; VAR y : INTEGER) : INTEGER;
BEGIN
    IF x = 0 THEN
        RETURN y + 1
    ELSIF y = 0 THEN
        RETURN acker(x - 1, 1)
    ELSE
        RETURN acker(x - 1, acker(x, y - 1))
    END
END acker;

BEGIN
    a := 3;
    b := 2;
    x := acker(a,b)
END ackermann.

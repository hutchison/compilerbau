# Compilerbau

## Überblick

### Analysephase/Frontend

* lexikalische Analyse: erkennen und klassifizieren der Lexeme ⇒ Tokenfolge
* Tokenfolge → Syntaxanalyse ⇒ Syntaxbaum
* Syntaxbaum → semantische Analyse ⇒ dekorierter Syntaxbaum
* Erzeugung der Zwischenrepräsentation

Dazu noch Symboltabelle und Fehlerdiagnose

### Synthesephase/Backend

* Zwischenrepräsentation ↔ Optimierung
  * einmal maschinenunabhängige Optimierung
  * und danach maschinenabhängige Optimierung
* Codeerzeugung → Zielcode

### Pässe eines Compilers

* Pass = Zusammenfassung von Phasen, die ineinander verschränkt ausgeführt
  werden
* Vorteil: Information von Pass i über gesamtes Programm steht in Pass i+1 zur
  Verfügung
* Bsp: Variablen und Funktionen müssen am Anfang deklariert werden ⇒ gestattet
  1-Pass-Kompilierung

## Lexikalische Analyse

* untrennbare Zeichenfolgen zusammenfassen und klassifizieren
* Token = Zeichenkette, der von einer formalen Grammatik ein Typ zugewiesen wird
* Lexem = dem Token zugrundeliegende Zeichenkette

* Problem: Tokenklasse „ganze Zahl“ Anfangsstück von Tokenklasse „Gleitkommazahl“
  * Lösung 1: spezielle Kennzeichnung: `i102` vs. `f102.3E-92`
  * Lösung 2 (Standard): längere Zeichenreihe wird ausgewählt

* Problem: Tokenklasse „Bezeichner“ und reservierte Schlüsselwörter
* Darf ich eine Variable `while` nennen? Und wie erkennen wir, dass wir gerade
  ein reserviertes Schlüsselwort eingelesen haben?
  * Lösung 1: Passt Zeichenreihe auf mehrere Spezifikationen, wird die erste
    passende Tokenklasse gewählt. Dabei stehen die Schlüsselwörter an erster
    Stelle.
  * Lösung 2: Schlüsselwörter in Symboltabelle für Bezeichner eintragen &
    speziell kennzeichnen

### Klassifikation der Lexeme
* Automat für jede Tokenklasse
* Variante 1: jeden Automaten parallel laufen lassen, bis keiner mehr fortsetzen
  kann (also DEA in Zustand ∅)
* Variante 2: einen großen Automaten konstruieren, verschiedene Endzustände
  repräsentieren verschiedene Klassen
* Vorteil von 1: kleinere Automaten (= kleineres Programm)
* Vorteil von 2: weniger Laufzeit

## Syntaktische Analyse

### Top-Down-Parsing



# Theorie für den 26.1.2018
* 3-Adresscode
* Registerallokation
* *keine* statische Analyse

### Analysephase/Frontend

* lexikalische Analyse: erkennen und klassifizieren der Lexeme => Tokenfolge
* Tokenfolge -> Syntaxanalyse => Syntaxbaum
* Syntaxbaum -> semantische Analyse => dekorierter Syntaxbaum
* Erzeugung der Zwischenrepräsentation

Dazu noch Symboltabelle und Fehlerdiagnose

### Synthesephase/Backend

* Zwischenrepräsentation <-> Optimierung
  * einmal maschinenunabhängige Optimierung
  * und danach maschinenabhängige Optimierung
* Codeerzeugung -> Zielcode

### Pässe eines Compilers

* Pass = Zusammenfassung von Phasen, die ineinander verschränkt ausgeführt werden
* Vorteil: Information von Pass i über gesamtes Programm steht in Pass i+1 zur Verfügung
* Bsp: Variablen und Funktionen müssen am Anfang deklariert werden => gestattet 1-Pass-Kompilierung

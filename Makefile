.PHONY: clean

UEBUNGEN := $(wildcard uebung*.pdf)

clean:
	$(RM) *.aux *.log *.fls *.out *.fdb_latexmk *.xdv

%.pdf-live: %.latex
	latexmk -pdf -xelatex -use-make -pvc $<

%.pdf: %.latex
	latexmk -pdf -xelatex -use-make $<

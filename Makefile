all: doc
	@echo "No code yet :)"

doc: doc/src/H4203-ADENOT-BRODU-CompteRenduPilote.tex
	cd doc/src && pdflatex H4203-ADENOT-BRODU-CompteRenduPilote.tex && mv H4203-ADENOT-BRODU-CompteRenduPilote.pdf ../../ && cd ../../

CC = g++
CFLAGS = -std=c++17 -g -Wall

F0  = p04_code_analyzer
F1  = analisis_ficheros
F2  = detectar_main
F3  = detectar_variables
F4  = detectar_bucles
F5  = detectar_comentarios
FH  = .h
FCC = .cc

PROGRAM = p04_code_analyzer

all: $(PROGRAM)
$(PROGRAM): $(F0)$(FCC)
	$(CC) $(CFLAGS) $(F0)$(FCC) $(F1)$(FCC) $(F2)$(FCC) $(F3)$(FCC) $(F4)$(FCC) $(F5)$(FCC) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)
	rm -rf fileout.txt
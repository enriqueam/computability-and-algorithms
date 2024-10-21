CC = g++
CFLAGS = -std=c++17 -g -Wall

F0  = p02_languages
F1  = simbolos
F2  = alfabetos
F3  = cadenas
F4  = lenguajes
FH  = .h
FCC = .cc

PROGRAM =  p02_languages

all: $(PROGRAM)
$(PROGRAM): $(F0)$(FCC)
	$(CC) $(CFLAGS) $(F0)$(FCC) $(F1)$(FCC) $(F2)$(FCC) $(F3)$(FCC) $(F4)$(FCC) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)
	rm -rf fileout.txt
CC = g++
CFLAGS = -std=c++17 -g -Wall

F0  = p01_strings
F1  = simbolos
F2  = alfabetos
F3  = cadenas
FH  = .h
FCC = .cc

PROGRAM =  p01_strings

all: $(PROGRAM)
$(PROGRAM): $(F0)$(FCC)
	$(CC) $(CFLAGS) $(F0)$(FCC) $(F1)$(FCC) $(F2)$(FCC) $(F3)$(FCC) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)
	rm -rf fileout.txt
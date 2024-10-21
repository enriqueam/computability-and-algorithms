CC = g++
CFLAGS = -std=c++17 -g -Wall

F0  = p06_automata_simulator
F1  = finite_automatas
F2  = states
F3  = transitions
F4  = strings
F5	= alphabets
F6	= symbols
FH  = .h
FCC = .cc

PROGRAM = p06_automata_simulator

all: $(PROGRAM)
$(PROGRAM): $(F0)$(FCC)
	$(CC) $(CFLAGS) $(F0)$(FCC) $(F1)$(FCC) $(F2)$(FCC) $(F3)$(FCC) $(F4)$(FCC)  $(F5)$(FCC) $(F6)$(FCC) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)
	rm -rf fileout.txt
CC = g++
CFLAGS = -std=c++17 -g -Wall

F0  = dfa2grammar
F1  = finite_automata
F2  = state
F3  = transition
F4  = string
F5	= alphabet
F6	= symbol
F7	= grammar
F8	= production
F9	= non_terminal_symbol
FH  = .h
FCC = .cc

PROGRAM = dfa2grammar

all: $(PROGRAM)
$(PROGRAM): $(F0)$(FCC)
	$(CC) $(CFLAGS) $(F0)$(FCC) $(F1)$(FCC) $(F2)$(FCC) $(F3)$(FCC) $(F4)$(FCC) $(F5)$(FCC) $(F6)$(FCC) $(F7)$(FCC) $(F8)$(FCC) $(F9)$(FCC) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)
	rm -rf fileout.txt
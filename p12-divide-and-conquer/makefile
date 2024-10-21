CC = g++
CFLAGS = -std=c++17 -g -Wall

F0  = main
F1  = bigint
FH  = .h
FCC = .cc

IDIR = ../include/
ODIR = ../src/
LDIR = ../lib/

PROGRAM = p12

all: $(PROGRAM)
$(PROGRAM): $(F0)$(FCC)
	$(CC) $(CFLAGS) $(F0)$(FCC) $(F1)$(FCC) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)
	rm -rf output.txt
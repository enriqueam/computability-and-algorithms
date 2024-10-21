CC = g++
CFLAGS = -std=c++11 -g -Wall

F0  = client
F1	= change_making
FH  = .h
FCC = .cc

PROGRAM = change_making

all: $(PROGRAM)
$(PROGRAM): $(F0)$(FCC)
	$(CC) $(CFLAGS) $(F0)$(FCC) $(F1)$(FCC) -o $(PROGRAM)

.PHONY: clean
clean:
	rm -rf $(PROGRAM)
	rm -rf fileout.txt
IDIR =../src
CC=g++
CFLAGS=-I$(IDIR) -static-libstdc++

ODIR=src

_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = *.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c $< $(CFLAGS)

traveller-problem: $(ODIR)/Route.o $(ODIR)/MainTSP.o $(ODIR)/City.o $(ODIR)/MontecarloHeuristic.o $(ODIR)/Problem.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o
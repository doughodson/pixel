
#
include ../makedefs

PGM = user-input

OBJS = main.o

all: $(PGM)

$(PGM) : $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)


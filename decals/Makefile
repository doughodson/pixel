
#
include ../makedefs

PGM = decals

OBJS = main.o

all: $(PGM)

$(PGM) : $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)


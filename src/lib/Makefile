IDIR =../include
CXX=g++
CXXFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm -lgtest -lpthread -lgtest_main

_DEPS = romanToArabic.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = mainTest.o romanToArabic.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

mainTest: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

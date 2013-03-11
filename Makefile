# Feel free to adapt this Makefile to your needs.
CXX        = g++-4.7

ifdef DEBUG
	CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -O0 -g `pkg-config --cflags alure`
else
	CXXFLAGS = -std=c++11 -O2 -DNDEBUG `pkg-config --cflags alure`
endif

LDFLAGS    = `pkg-config --libs alure`
TARGET     = audioxx


all: $(TARGET)


$(TARGET): main.o
	$(CXX) $(LDFLAGS) $(CXXFLAGS) main.o -o $(TARGET)

main.o: main.cpp Buffer.hpp Device.hpp Player.hpp Source.hpp Stream.hpp Link.hpp
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -f *.o $(TARGET)

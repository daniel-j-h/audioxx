# Feel free to adapt this Makefile to your needs.
CXX        = g++-4.7
CXXFLAGS   = -std=c++11 -Wall -Wextra -pedantic -O0 -g -Wall -Wextra -pedantic `pkg-config --cflags alure`
LDFLAGS    = `pkg-config --libs alure`
TARGET     = audioxx


all: $(TARGET)


$(TARGET): main.o
	$(CXX) $(LDFLAGS) $(CXXFLAGS) main.o -o $(TARGET)

main.o: main.cpp Buffer.hpp Device.hpp Player.hpp Source.hpp
	$(CXX) $(CXXFLAGS) -c $<


clean:
	rm -f *.o $(TARGET)

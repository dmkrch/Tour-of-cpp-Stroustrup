CXX = g++
CXXFLAGS = -g -Wall

run:
	./WumpusGame
clean:
	rm -f *.o WumpusGame

Gameplay.o: Gameplay.cpp Gameplay.h
	$(CXX) $(CXXFLAGS) -c Gameplay.cpp -o Gameplay.o

WumpusGame: main.cpp Gameplay.o
	$(CXX) $(CXXFLAGS) main.cpp Gameplay.o -o WumpusGame
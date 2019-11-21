main: main.o Animal.o Tiger.o Penguin.o Turtle.o Zoo.o
	g++ -std=c++11 main.o Animal.o Tiger.o Penguin.o Turtle.o Zoo.o -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Animal.o: Animal.cpp Animal.hpp
	g++ -std=c++11 -c Animal.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	g++ -std=c++11 -c Tiger.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -std=c++11 -c Penguin.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	g++ -std=c++11 -c Turtle.cpp

Zoo.o: Zoo.cpp Zoo.hpp
	g++ -std=c++11 -c Zoo.cpp

clean:
	rm *.o main

settlers: main.o Player.o Board.o Referee.o Resources.o
	g++ main.o Player.o Board.o Referee.o Resources.o -o settlers
	rm -f *.o

clean:
	rm -f settlers *.o

main.o: main.cpp
	g++ -c main.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

Referee.o: Referee.cpp Referee.h
	g++ -c Referee.cpp

Resource.o: Resources.cpp Resource.h
	g++ -c Resources.cpp
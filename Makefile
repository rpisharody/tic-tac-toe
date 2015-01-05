all: objs

objs: main.c tictactoe.o
	g++ -Wall -O2 -o ttt main.c tictactoe.o
tictactoe.o: tictactoe.c tictactoe.h
	g++ -Wall -O2 -c -o tictactoe.o tictactoe.c

clean:
	-rm *.o

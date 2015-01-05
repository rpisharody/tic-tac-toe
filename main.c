#include "tictactoe.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int getMove(void);

int main() {
	char BOARD[SIZE];
	Player P1 = Man;
	for (int ii = 0; ii < SIZE; ++ii)
		BOARD[ii] = '_';

	// Man : X
	// Machine : O

 	// BOARD[1] = 'X'; 
 	// BOARD[4] = 'X';
 
 	// BOARD[0] = 'O';

	show (BOARD);
	// int pos = move(BOARD, Machine);
 	// cout << "Machine plays : " << pos << endl;
	int pos;
	while ( ! (isWin(BOARD) || isFull (BOARD) ) ) {
		if (P1 == Man) {
			pos = getMove();
			BOARD[pos] = 'X';
			P1 = Machine;
		} else {
			pos = move(BOARD, P1);
			BOARD[pos] = 'O';
			P1 = Man;
		}
		system("clear");
		show (BOARD);
	}
	cout << "Game Over !! " << endl;
	if (isWin(BOARD) ){
		cout << (P1 == Man ? "Machine" : "You")
		     << " Won !" << endl;
	} else if (isFull(BOARD)) {
		cout << "Its a Draw !" << endl;
	}
	return 0;
}

int getMove(void) {
	cout << "Enter Position : ";
	int pos;
	cin >> pos;
	return pos;
}

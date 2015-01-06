#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

#include "tictactoe.h"

using std::cout;
using std::endl;
using std::cin;
using std::map;
using std::make_pair;

bool isWin(char *b) {
	// Function to check if the board is a win.
	
	if (
		// Rows
		isEqual (b  , b+1, b+2) ||
		isEqual (b+3, b+4, b+5) ||
		isEqual (b+6, b+7, b+8) ||
		// Columns
		isEqual (b  , b+3, b+6) ||
		isEqual (b+1, b+4, b+7) ||
		isEqual (b+2, b+5, b+8) ||
		//Diagonals
		isEqual (b  , b+4, b+8) ||
		isEqual (b+2, b+4, b+6) )
			return true;
	else
		return false;
}	

bool isFull (char *b) {
	for (int ii = 0; ii < SIZE; ++ii) {
		if ( (*(b+ii) == '_' )) 
			return false;
	}
	return true;
}

bool isEqual (char *a, char *b, char *c) {
	if ( (*a == 'X') || (*a == 'O') ) {
		if ( *a == *b) {
			if ( *b == *c ) {
				return true;
			}
		}
	}
	return false;
}

bool isLegal (char *b, const int& pos) {
	if ( *(b + pos) == '_' )
		return true;
	else
		return false;
}

int convert (const int& x, const int& y) {
	return ( ((x - 1)*sqrtSIZE) + (y - 1) );
}

void show(char *b) {
	for (int ii = 0; ii < SIZE; ++ii) {
		std::cout << * (b + ii) << " ";
		if ( ! ( (ii +1 ) % 3))
			std::cout << std::endl;
	}
}

int move(char *b, Player p, int depth) {
	// Make legal moves
	map<int, int> Moves;
	
	// Calculate scores for all possible Moves
	for (int ii = 0; ii < SIZE; ++ii) {
		if (isLegal(b, ii)) {
			b[ii] = (p == Man ? 'X' : 'O');
			if (isWin(b)) {
				if (p == Man) {
					Moves.insert(make_pair((depth - 10), ii));
				} else {
					Moves.insert(make_pair((10 - depth), ii));
				}
			} else if (isFull(b)) {
				Moves.insert(make_pair(0, ii));
			} else {
				// Switch player 
				Player next = (p == Man ? Machine : Man);
				int tmp = move(b, next, depth + 1);
				Moves.insert(make_pair(tmp, ii));
			}
			b[ii] = '_';
		}
	}
	if (depth == 1) {
		return Moves.rbegin() -> second;
	} else {
		if (p == Machine)
			return Moves.rbegin() -> first;
		else
			return Moves.begin() -> first;
	}
}

#ifndef __GUARD__tictactoe
#define __GUARD__tictactoe

#define SIZE 9
#define sqrtSIZE 3

enum Player {Man, Machine};

// Conversion functions
int convert(const int&, const int&);

bool isWin  (char *);
bool isFull (char *);
bool isEqual (char *, char *, char *);
bool isLegal (char *, const int&);
void show(char *);

// Brains of the program
int move(char *, Player, int depth = 1);


#endif

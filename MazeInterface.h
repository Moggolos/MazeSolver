#include "StackInterface.h"

extern int moves[4][4];

extern void adjustMoves(int rows,int columns);
extern tile** makegrid(tile *start,tile *goal);
extern int solveMaze(tile* start,tile* goal,tile** grid);
extern void printMaze(tile **grid,int rowbound,int colbound);


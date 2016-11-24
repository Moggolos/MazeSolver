#include <stdio.h>
#include <stdlib.h>
#include "MazeInterface.h"

int main(void){
    int flag;
    tile start,goal;
    tile ** grid;
    grid = makegrid(&start,&goal);
    if (grid==NULL){
        printf("Couldn't allocate memory.\n");
        return -1;
    }
    flag = solveMaze(&start,&goal,grid);
    if(flag){
        printf("Maze can be solved.\n");
        printMaze(grid,moves[1][2],moves[2][3]);
    }
    else
        printf("No solution found.\n");

    return 0;
}

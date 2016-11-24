#include <stdio.h>
#include <stdlib.h>
#include "MazeInterface.h"



int moves[4][4] = {{-1,0,0,-1},  /*up*/
                    {1,0,0,-1},  /*down*/
                    {0,1,-1,0},  /*right*/
                   {0,-1,-1,0}}; /*left*/







void adjustMoves(int rows,int columns){
       moves[1][2]=rows-1;
       moves[2][3]=columns-1;

}




tile** makegrid(tile *start,tile *goal){
    int rows,columns,i,j;
    char ch;
    tile **grid;

    scanf("%d %d",&rows,&columns);
    adjustMoves(rows,columns);
    getchar(); /*Eat new line*/
    grid=malloc(rows*sizeof(tile *));
    if(grid==NULL)
        return NULL;
    for(i=0;i<rows;i++){
        grid[i]=malloc(columns*sizeof(tile));
        if(grid[i]==NULL)
            return NULL;
    }


    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            grid[i][j].x=i;
            grid[i][j].y=j;
            grid[i][j].visited=0;
            ch=getchar();
            if(ch=='.')
                grid[i][j].identity=0;
            else if(ch=='#')
                grid[i][j].identity=1;
            else if(ch=='S'){
                grid[i][j].identity=2;
                grid[i][j].visited=1;
                *start = grid[i][j];
            }
            else if(ch=='G'){
                grid[i][j].identity=3;
                *goal = grid[i][j];
            }
            else{
                printf("Invalid input\n");
                exit(0);
            }
        }
        getchar();                          /*Eat new line*/
    }
    return grid;

}

int solveMaze(tile* start,tile* goal,tile** grid){
    int flag=0,i;
    Stack S;
    tile curTile;
    InitializeStack(&S);
    Push(*start,&S);

    while(!Empty(&S)){
        Pop(&S,&curTile);
        if(curTile.x==goal->x&&curTile.y==goal->y){
            while(!Empty(&S))
                Pop(&S,&curTile);
            return 1;
        }
        for(i=0;i<4;i++){
            flag=0;
            if(curTile.y!=moves[i][3]&&curTile.x!=moves[i][2]&&grid[curTile.x+moves[i][0]][curTile.y+moves[i][1]].visited==0&&grid[curTile.x+moves[i][0]][curTile.y+moves[i][1]].identity!=1){
                Push(grid[curTile.x][curTile.y], &S);
                grid[curTile.x+moves[i][0]][curTile.y+moves[i][1]].visited=1;
                grid[curTile.x+moves[i][0]][curTile.y+moves[i][1]].isPath=1;
                Push(grid[curTile.x+moves[i][0]][curTile.y+moves[i][1]],&S);
                flag = 1;
                break;

            }
        }
        if(flag==0){
            grid[curTile.x][curTile.y].isPath=0;
        }

    }
    return 0;
}

void printMaze(tile **grid,int rowbound,int colbound){
    int i,j;
    for(i=0;i<=rowbound;i++){
        for(j=0;j<=colbound;j++){
            if(grid[i][j].isPath==1&&grid[i][j].identity==0){
                putchar('+');
            }
            else if(grid[i][j].identity==0){
                putchar('.');
            }
            else if(grid[i][j].identity==1){
                putchar('#');
            }
            else if(grid[i][j].identity==2){
                putchar('S');
            }
            else putchar('G');
        }
        putchar('\n');

    }
    return;


}

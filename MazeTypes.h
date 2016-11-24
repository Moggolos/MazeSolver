

typedef struct {
    int x,y; /*x=row, y=column*/
    int identity; /* 0 = . , 1 = # , 2 = S, 3 = G*/
    int visited;
    int isPath;
}tile;


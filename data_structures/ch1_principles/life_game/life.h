#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define MAXROW 20
#define MAXCOL 60

typedef enum state { DEAD, ALIVE } State;
typedef State Grid[MAXROW + 2][MAXCOL + 2];

// copy updated grid (newmap) into map
void copy_map(Grid map, Grid newmap);

// will ask the user if they want to go to the next generation
bool generate_next(void);

// initialize the grid and input initial configuration
void init(Grid map);

// counts the number of occuped cells adjacent to row, col
int neighbor_count(Grid map, int row, int col);

// outputs the map to the terminal
void write_map(Grid map);

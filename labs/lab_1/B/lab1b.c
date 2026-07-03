/*
 * lab1b.c
 * Created on: 07/02/26
 * Author: Peter Duncanson
 */

#include "lifegame.h"
#include <stdio.h>

#define NUM_GENERATIONS 50

void next_generation();
int get_next_state(int x, int y);
int num_neighbors(int x, int y);

int main(int argc, char **argv) {

    if (argc == 0) {
        printf("Error, file type must be passed in\n");
        return 1;
    } 
    
    initialize_world_from_file(argv[1]);

    for (int i=0; i<NUM_GENERATIONS; i++) {
        next_generation();
    }

    save_world_to_file("world.txt");

	return 0;
}

void next_generation() {
    int height = get_world_height();
    int width = get_world_width();
    for (int row=0; row<height; row++) {
        for (int col=0; col<width; col++) {
            set_cell_state(col, row, get_next_state(col, row));
        }
    }
	finalize_evolution();
}

int get_next_state(int x, int y) {
    int alive = get_cell_state(x, y);
    int n = num_neighbors(x, y);
    if (alive != ALIVE) {
        if (n == 3) { return ALIVE; }
        else { return DEAD; }
    }
    else {
        if (n == 3 || n == 2) { return ALIVE; }
        else if (n < 2 || n > 3) { return DEAD; }
    }
    return -1;
}

int num_neighbors(int x, int y) {
    int n_alive = 0;
    for (int col=-1; col<=1; col++) {
        for (int row=-1; row<=1; row++) {
            if (col == 0 && row == 0) { continue; }
            else if (get_cell_state(x+col, y+row) == ALIVE) { n_alive++; }
        }
    }
    return n_alive; 
}

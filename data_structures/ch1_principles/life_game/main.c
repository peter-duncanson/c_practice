#include <stdio.h>
#include <unistd.h>
#include "life.h"

int main(void)
{
    int row, col;
    bool manual, all_dead;
    Grid map;
    Grid newmap;
    init(map);
    writeMap(map);

    printf("This is the initial configuration you have chosen.\n"
           "Press < Enter > to continue\n");
    while (getchar() != '\n');

    do
    {
        for (row = 1; row <= MAXROW; row++)
        {
            for (col = 1; col <= MAXCOL; col++)
            {
                switch (neighborCount(map, row, col))
                {
                    case 0:
                    case 1:
                        newmap[row][col] = DEAD;
                        break;
                    case 2:
                        newmap[row][col] = map[row][col];
                        break;
                    case 3:
                        newmap[row][col] = ALIVE;
                        break;
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        newmap[row][col] = DEAD;
                        break;
                }
            }
        }
        copyMap(map, newmap);
        writeMap(map);
        usleep(500000);
        // printf("Do you wish to continue?");

    } while (true);

}

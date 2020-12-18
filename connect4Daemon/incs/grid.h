#ifndef GRID_H
# define GRID_H

# define GRID_HEIGHT 6
# define GRID_WIDTH 7

# include <json-c/json.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "cell.h"

typedef struct          s_grid
{
    t_cell              grid[GRID_HEIGHT][GRID_WIDTH];
    e_value             iaColor;
    int                 lastColumnPlayerCoin; // -1 if NULL else 0 <-> (GRID_WIDTH - 1)
}                       t_grid;

bool                    initGrid(t_grid *grid, char const *requestGrid);
void                    printGrid(t_grid const *grid);

#endif
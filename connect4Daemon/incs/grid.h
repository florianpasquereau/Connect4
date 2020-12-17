#ifndef GRID_H
# define GRID_H

# define GRID_HEIGHT 6
# define GRID_WIDTH 7

# include <json-c/json.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>

# include "cell.h"

typedef struct          s_grid
{
    t_cell              *grid[GRID_HEIGHT][GRID_WIDTH];
    e_value             iaColor;
}                       t_grid;

void                    initGrid(t_grid *grid, char const *requestGrid);
void                    destructGrid(t_grid *grid);
void                    initGridFromString(t_grid *grid, struct json_object *gridArray, e_value const iaColor);
void                    printGrid(t_grid const *grid);

#endif
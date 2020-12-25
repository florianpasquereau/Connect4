#ifndef CELL_H
# define CELL_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef enum            value {
    EMPTY,
    RED,
    YELLOW
}                       e_value;

typedef struct          s_cell
{
    e_value             value;
}                       t_cell;

char                    *printCell(t_cell const *cell);
bool                    cellSetValue(t_cell *cell, e_value value);
e_value const           *cellgetValue(t_cell const *cell);


#endif
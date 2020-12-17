#ifndef CELL_H
# define CELL_H

# include <stdlib.h>
# include <stdio.h>

typedef enum            value {
    EMPTY,
    RED,
    YELLOW
}                       e_value;

typedef struct          s_cell
{
    e_value             value;
}                       t_cell;

t_cell                  *cellFactory(int const cellValue);
char                    *printCell(t_cell const *cell);


#endif
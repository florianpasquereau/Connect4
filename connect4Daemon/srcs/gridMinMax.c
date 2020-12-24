#include "../incs/grid.h"

bool                    findColumnIaSelected(t_grid *grid, unsigned char *columnIaSelected, char *message)
{    
    if (grid == NULL) {
        strncpy(message, "Grid is null", BUFFER_SIZE_MESSAGE);
        return false;
    }
    if (grid->cellFilled == 0) {
        (*columnIaSelected) = GRID_WIDTH / 2;
        strncpy(message, "Grid Empty", BUFFER_SIZE_MESSAGE);
    } else if ((*gridGetGameFinish(grid))) {
        strncpy(message, "Game is finish", BUFFER_SIZE_MESSAGE);
    } else {
         e_value const    *value;
        do {
            (*columnIaSelected) = rand() % GRID_WIDTH;
        } while ((value = cellgetValue(gridGetCell(grid, (*columnIaSelected), 0))) == NULL || value == EMPTY);
        strncpy(message, "Random column selected", BUFFER_SIZE_MESSAGE);
    }
    return true;
}
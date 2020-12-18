#include "../incs/cell.h"

bool                    cellSetValue(t_cell *cell, e_value value) 
{
    if (cell == NULL) {
        return false;
    }
    cell->value = value;
    return true;
}

char                    *printCell(t_cell const *cell)
{
    if (cell == NULL) {
        return "ERROR";
    }
    switch (cell->value) {
        case RED:
            return " \033[0;31mR\033[0m";
        case YELLOW:
            return " \033[0;33mY\033[0m";
        default:
            return " .";
    }
}
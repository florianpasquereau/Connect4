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
        // return " R";
            return " \033[0;31mR\033[0m";
        case YELLOW:
            // return " Y";
            return " \033[0;33mY\033[0m";
        default:
            return " .";
    }
}

char                    *printCellSelected(t_cell const *cell)
{
    if (cell == NULL) {
        return "ERROR";
    }
    switch (cell->value) {
        case RED:
        // return " R";
            return " \033[0;35mR\033[0m";
        case YELLOW:
            // return " Y";
            return " \033[0;35mY\033[0m";
        default:
            return " .";
    }
}

e_value const           *cellgetValue(t_cell const *cell)
{
    if (cell == NULL) {
        return NULL;
    }
    return &cell->value;
}
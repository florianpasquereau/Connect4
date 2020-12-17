#include "../incs/cell.h"

t_cell                  *cellFactory(int const cellValue) {
    e_value             value;
    t_cell              *cell = (t_cell*)malloc(sizeof(t_cell));
    
    if (cell == NULL) {
        return cell;
    }
    switch (cellValue) {
        case 1:
            value = RED;
            break ;
        case 2:
            value = YELLOW;
            break;
        default:
            value = EMPTY;
    }
    cell->value = value;
    return cell;
}

char                    *printCell(t_cell const *cell)
{
    switch (cell->value) {
        case RED:
            return " \033[0;31mR\033[0m";
        case YELLOW:
            return " \033[0;33mY\033[0m";
        default:
            return " .";
    }
}
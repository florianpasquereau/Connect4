#include "../incs/grid.h"

static bool             loopMin(t_grid *grid, unsigned int const deep, unsigned int lastX, long int *score);
static bool             loopMax(t_grid *grid, unsigned int const deep, unsigned int lastX, long int *score);

bool                    loopMin(t_grid *grid, unsigned int const deep, unsigned int lastX, long int *score) {
    unsigned int        x;
    long int            scoreFunc = LONG_MAX;
    long int            tmp = 0;
    e_value const       *currentCellValue;

    if (cellWinner(grid, grid->startColumns[lastX] + 1, lastX) == true || deep == 0) { //end loopMax
        (*score) = scoringCell(grid, grid->startColumns[lastX] + 1, lastX, deep);
        return true;
    }
    for(x = 0; x < GRID_WIDTH; x++) {
        if ((currentCellValue = cellgetValue(gridGetCell(grid, 0, x))) == NULL) {
            return false;
        } else if ((*currentCellValue) != EMPTY) {
            continue;
        }
        if (gridSetCell(grid, x, grid->playerColor) == false || loopMax(grid, deep -1, x, &tmp) == false) {
            return false;
        } else if (tmp < scoreFunc) {
            scoreFunc = tmp;
            // printGridChecker(grid, grid->startColumns[x] + 1, x);
            // printf("\033[0;33mYellow\033[0m column[%u] score : %ld WorstScore = %ld on column : %u\n", x, tmp, scoreFunc, x);
        }
        if (gridSetCell(grid, x, EMPTY) == false) { //remove the coin tested
            return false;
        }
    }
    *score = scoreFunc;
    return true;  
}

bool                    loopMax(t_grid *grid, unsigned int const deep, unsigned int lastX, long int *score) {
    unsigned int        x;
    long int            scoreFunc = LONG_MIN;
    long int            tmp = 0;
    e_value const       *currentCellValue;

    if (cellWinner(grid, grid->startColumns[lastX] + 1, lastX) == true || deep == 0) { //end loopMin
        (*score) = scoringCell(grid, grid->startColumns[lastX] + 1, lastX, deep) * -1;
        return true;
    }
    for(x = 0; x < GRID_WIDTH; x++) {
        if ((currentCellValue = cellgetValue(gridGetCell(grid, 0, x))) == NULL) {
            return false;
        } else if ((*currentCellValue) != EMPTY) {
            continue;
        }
        if (gridSetCell(grid, x, grid->iaColor) == false || loopMin(grid, deep - 1, x, &tmp) == false) {
            return false;
        } else if (tmp > scoreFunc) {
            scoreFunc = tmp;
            // printf("\033[0;31mRED\033[0m column[%u] score : %ld bestScore = %ld on column : %u\n", x, tmp, scoreFunc, x);
            // printGridChecker(grid, grid->startColumns[x] + 1, x);
        }
        if (gridSetCell(grid, x, EMPTY) == false) { //remove the coin tested
            return false;
        }
    }
    *score = scoreFunc;
    return true;  
}

static bool             startMinMax(t_grid *grid, unsigned int *columnIaSelected) {
    unsigned int        x;
    long int            scoreFunc = LONG_MIN;
    long int            tmp;
    e_value const       *currentCellValue;

    (*columnIaSelected) = 0xffffffff;
    for(x = 0; x < GRID_WIDTH; x++) {
        if ((currentCellValue =  cellgetValue(gridGetCell(grid, 0, x))) == NULL) {
            return false;
        } else if ((*currentCellValue) != EMPTY) {
            continue;
        }
        if (gridSetCell(grid, x, grid->iaColor) == false || loopMin(grid, GRID_DEEP - 1, x, &tmp) == false) {
            return false;
        } else if (tmp > scoreFunc) {
            scoreFunc = tmp;
            (*columnIaSelected) = x;
        }
        printf("END column[%u] score : %ld bestScore = %ld on column : %u\n", x, tmp, scoreFunc, x);
        printGridChecker(grid, grid->startColumns[x] + 1, x);
        if (gridSetCell(grid, x, EMPTY) == false) {
            return false;
        }
    }
    printf("columnSelected = %u with a score of %ld\n------------------------------\n", *columnIaSelected, scoreFunc);
    return true;
}

bool                    findColumnIaSelected(t_grid *grid, unsigned int *columnIaSelected, char *message)
{   
    if (grid == NULL) {
        strncpy(message, "Grid is null", BUFFER_SIZE_MESSAGE);
        return false;
    }
    if (grid->cellFilled == 0 || grid->cellFilled == 1) {
        (*columnIaSelected) = GRID_WIDTH / 2;
        strncpy(message, "Grid Empty or with one coin", BUFFER_SIZE_MESSAGE);
    } else if ((*gridGetGameFinish(grid))) {
        strncpy(message, "Game is finish", BUFFER_SIZE_MESSAGE);
    } else {
        if (startMinMax(grid, columnIaSelected) == false) {
            strncpy(message, "Not possible to find the selected column", BUFFER_SIZE_MESSAGE);
            return false;
        }
        strncpy(message, "IA column selected", BUFFER_SIZE_MESSAGE);
    }
    return true;
}
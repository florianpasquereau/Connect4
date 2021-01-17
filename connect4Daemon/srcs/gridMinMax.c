#include "../incs/grid.h"

static bool             loopMin(t_grid *grid, unsigned int const deep, unsigned int lastX, long int *score);
static bool             loopMax(t_grid *grid, unsigned int const deep, unsigned int lastX, long int *score);
static const unsigned int       
                        orderCheckCoin[GRID_WIDTH][GRID_WIDTH] = {
    {0u, 1u, 2u, 3u, 4u, 5u, 6u},
    {1u, 0u, 2u, 3u, 4u, 5u, 6u},
    {2u, 1u, 3u, 0u, 4u, 5u, 6u},
    {3u, 2u, 4u, 1u, 5u, 0u, 6u},
    {4u, 3u, 5u, 2u, 6u, 1u, 0u},
    {5u, 4u, 6u, 3u, 2u, 1u, 0u},
    {6u, 5u, 4u, 3u, 2u, 1u, 0u}
};

bool                    loopMin(t_grid *grid, unsigned int const deep, unsigned int lastX, long int *score) {
    unsigned int        i, x;
    long int            scoreFunc = LONG_MAX;
    long int            tmp = 0;
    e_value const       *currentCellValue;

    if (cellWinner(grid, grid->startColumns[lastX] + 1, lastX) == true || deep == 0) { //end loopMax
        (*score) = scoringCell(grid, grid->startColumns[lastX] + 1, lastX, deep);
        return true;
    } else if (lastX >= GRID_WIDTH) {
        return false;
    }
    for(i = 0; i < GRID_WIDTH; i++) {
        x = orderCheckCoin[lastX][i];
        if ((currentCellValue = cellgetValue(gridGetCell(grid, 0, x))) == NULL) {
            return false;
        } else if ((*currentCellValue) != EMPTY) {
            continue;
        }
        if (gridSetCell(grid, x, grid->playerColor) == false || loopMax(grid, deep -1, x, &tmp) == false) {
            return false;
        } else if (tmp < scoreFunc) {
            scoreFunc = tmp;
        }
        if (gridSetCell(grid, x, EMPTY) == false) { //remove the coin tested
            return false;
        }
    }
    *score = scoreFunc;
    return true;  
}

bool                    loopMax(t_grid *grid, unsigned int const deep, unsigned int lastX, long int *score) {
    unsigned int        i, x;
    long int            scoreFunc = LONG_MIN;
    long int            tmp = 0;
    e_value const       *currentCellValue;

    if (cellWinner(grid, grid->startColumns[lastX] + 1, lastX) == true || deep == 0) { //end loopMin
        (*score) = scoringCell(grid, grid->startColumns[lastX] + 1, lastX, deep) * -1;
        return true;
    } else if (lastX >= GRID_WIDTH) {
        return false;
    }
    for(i = 0; i < GRID_WIDTH; i++) {
        x = orderCheckCoin[lastX][i];
        if ((currentCellValue = cellgetValue(gridGetCell(grid, 0, x))) == NULL) {
            return false;
        } else if ((*currentCellValue) != EMPTY) {
            continue;
        }
        if (gridSetCell(grid, x, grid->iaColor) == false || loopMin(grid, deep - 1, x, &tmp) == false) {
            return false;
        } else if (tmp > scoreFunc) {
            scoreFunc = tmp;
        }
        if (gridSetCell(grid, x, EMPTY) == false) { //remove the coin tested
            return false;
        }
    }
    *score = scoreFunc;
    return true;  
}

static bool             startMinMax(t_grid *grid, unsigned int *columnIaSelected) {
    unsigned int        i, x;
    long int            scoreFunc = LONG_MIN;
    long int            tmp;
    e_value const       *currentCellValue;

    (*columnIaSelected) = 0xffffffff;
    if (grid->lastRowPlayerCoin >= GRID_WIDTH) {
        return false;
    }
    for(i = 0; i < GRID_WIDTH; i++) {
        x = orderCheckCoin[grid->lastRowPlayerCoin][i];
        //check if the column is full
        if ((currentCellValue =  cellgetValue(gridGetCell(grid, 0, x))) == NULL) {
            return false;
        } else if ((*currentCellValue) != EMPTY) {
            continue;
        }
        //stating the min loop
        if (gridSetCell(grid, x, grid->iaColor) == false || loopMin(grid, GRID_DEEP - 1, x, &tmp) == false) {//
            return false;
        } else if (tmp > scoreFunc) {
            scoreFunc = tmp;
            (*columnIaSelected) = x;
        }
        //remove the coin putted
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
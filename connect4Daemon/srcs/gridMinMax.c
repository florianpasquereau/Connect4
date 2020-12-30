#include "../incs/grid.h"

static unsigned int     getMinScore(unsigned int const currentScore, unsigned int const cellScore, unsigned int const x, unsigned int *columnSelected) {
    if (currentScore > cellScore) {
        *columnSelected = x;
        return cellScore;
    }
    return currentScore;
}

static unsigned int     getMaxScore(unsigned int const currentScore, unsigned int const cellScore, unsigned int const x, unsigned int *columnSelected) {
    if (currentScore < cellScore) {
        *columnSelected = x;
        return cellScore;
    }
    return  currentScore;
}

static unsigned int    loopMinMax(t_grid *grid, 
    e_value const cellValue, 
    unsigned int const deep,
    unsigned int lastX,
    unsigned int *score,
    unsigned int *columnSelected)
{
    unsigned int        x;
    e_value const       *currentCellValue;
    unsigned int        (*f)(unsigned int const, unsigned int const, unsigned int const, unsigned int *);

    if (deep == 0) {
        return scoringCell(grid, grid->startColumns[lastX] + 1, lastX);
    }
    f = cellValue == grid->iaColor ? getMaxScore : getMinScore;
    for (x = 0; x < GRID_WIDTH; x++) {
        if ((currentCellValue =  cellgetValue(gridGetCell(grid, 0, x))) == NULL || (*currentCellValue) != EMPTY) {
            continue;
        }
        if (gridSetCell(grid, x, cellValue) == false) {
            return *score;
        }
        (*score) = f((*score), loopMinMax(grid, cellValue == RED ? YELLOW : RED, deep - 1, x, score, columnSelected), x, columnSelected);
        cellWinner(grid, grid->startColumns[x] + 1, x);
        printf("grid[%u][%u] %s => : %u\n", grid->startColumns[x] + 1, x, cellValue == grid->iaColor ? "MAX" : "MIN", *score);
        printGrid(grid);
        if (gridSetCell(grid, x, EMPTY) == false) {
            return *score;
        }
    }
    return *score;
}

bool                    findColumnIaSelected(t_grid *grid, unsigned int *columnIaSelected, char *message)
{   
    unsigned int        score;
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
        score = GRID_DEEP % 2 == 1 ? 0 : 0xffffffff;
        loopMinMax(grid, RED, GRID_DEEP, 0, &score, columnIaSelected);
        printf("columnSelected = %u\n------------------------------\n", *columnIaSelected);
        // e_value const    *value;
        // do {
        //     (*columnIaSelected) = rand() % GRID_WIDTH;
        //     printf("%s %d : columnIaSelected : %u\n", __FILE__, __LINE__, (*columnIaSelected));
        // } while ((value = cellgetValue(gridGetCell(grid, 0, (*columnIaSelected)))) == NULL || (*value) != EMPTY);
        strncpy(message, "Random column selected", BUFFER_SIZE_MESSAGE);
    }
    return true;
}
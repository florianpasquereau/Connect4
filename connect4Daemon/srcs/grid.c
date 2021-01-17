#include "../incs/grid.h"

static unsigned int     initGridLastRowPlayerCoin(t_grid const *grid) {
    unsigned int        y;
    unsigned int const  *x;
    e_value const       *cellValue;

    if ((x = gridGetLastColumnPayerCoin(grid)) != NULL && (*x) != 0xffffffff) {
        for(y = 0; y < GRID_HEIGHT; y++) {
            if ((cellValue = cellgetValue(gridGetCell(grid, y, (*x)))) != NULL && (*cellValue) != EMPTY) {
                return y;
            }
        }
    }
    return 0xffffffff;
}

static bool             initGridFromString(t_grid *grid, struct json_object *gridArray, e_value const iaColor, unsigned int const lastColumnPlayerCoin) {
    struct json_object  *gridRow;
    unsigned int        x;
    struct json_object  *cellValue;
    e_value             value;

    if (grid == NULL || gridArray == NULL || json_object_array_length(gridArray) != GRID_HEIGHT) {
        return false;
    } else if (lastColumnPlayerCoin >= GRID_WIDTH && lastColumnPlayerCoin != 0xffffffff) {
        return false;
    }
    for(x = 0; x < GRID_WIDTH; x++) {
        grid->startColumns[x] = 0xffffffff;
    }
    for (unsigned int y = 0; y < GRID_HEIGHT; y++) {
        gridRow = json_object_array_get_idx(gridArray, y);
        if (json_object_array_length(gridRow) != GRID_WIDTH) {
            return false;
        }
        for(x = 0; x < GRID_WIDTH; x++) {
            cellValue = json_object_array_get_idx(gridRow, x);
            value = json_object_get_int(cellValue);
            if (cellSetValue((t_cell *)gridGetCell(grid, y, x), value) == false) {
                return false;
            }
            if (value != EMPTY) {
                grid->cellFilled++;
            } else {
                grid->startColumns[x] = y;
            }
        }
    }
    grid->iaColor = iaColor;
    grid->playerColor = iaColor == RED ? YELLOW : RED;
    grid->lastColumnPlayerCoin = lastColumnPlayerCoin;
    grid->lastRowPlayerCoin = initGridLastRowPlayerCoin(grid);
    grid->gameFinish = cellWinner(grid, *gridGetLastRowPayerCoin(grid), *gridGetLastColumnPayerCoin(grid));
    return true;
}

bool                    initGrid(t_grid *grid, char const *requestGrid) {
    if (grid == NULL || requestGrid == NULL) {
        return false;
    }
    memset(grid, 0, sizeof(t_grid));
    struct json_object  *requestParsed = json_tokener_parse(requestGrid);
    struct json_object  *gridArray;
    struct json_object  *colorIa;
    struct json_object  *lastColumnPlayerCoin;

    json_object_object_get_ex(requestParsed, "grid", &gridArray);
    json_object_object_get_ex(requestParsed, "color_ia", &colorIa);
    json_object_object_get_ex(requestParsed, "last_column_player_coin", &lastColumnPlayerCoin);
    return initGridFromString(grid, gridArray, json_object_get_int(colorIa), (unsigned int)json_object_get_int64(lastColumnPlayerCoin));
}

t_cell const            *gridGetCell(t_grid const *grid, unsigned int const y, unsigned int const x) {
    if (grid == NULL || y >= GRID_HEIGHT || x >= GRID_WIDTH) {
        return NULL;
    }
    return &grid->grid[y][x];
}

bool                    gridSetCell(t_grid *grid, unsigned int const x, e_value const cellValue)
{
    unsigned int        y;

    if (grid == NULL || x >= GRID_WIDTH) {
        return false;
    }
    y = cellValue == EMPTY ? grid->startColumns[x] + 1 : grid->startColumns[x];
    if (cellSetValue((t_cell *)gridGetCell(grid, y, x), cellValue) == false) {
        return false;
    }
    grid->startColumns[x] = cellValue == EMPTY ? y : y - 1;
    return true;
}

e_value const           *gridGetAiColor(t_grid const *grid)
{
    if (grid == NULL) {
        return NULL;
    }
    return &grid->iaColor;
}

unsigned int const      *gridGetLastColumnPayerCoin(t_grid const *grid)
{
    if (grid == NULL) {
        return NULL;
    }
    return &grid->lastColumnPlayerCoin;
}

unsigned int const      *gridGetLastRowPayerCoin(t_grid const *grid)
{
    if (grid == NULL) {
        return NULL;
    }
    return &grid->lastRowPlayerCoin;
}

bool const              *gridGetGameFinish(t_grid const *grid) {
    if (grid == NULL) {
        return NULL;
    }
    return &grid->gameFinish;
}               
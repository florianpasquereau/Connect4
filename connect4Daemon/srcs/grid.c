#include "../incs/grid.h"

void                    initGrid(t_grid *grid, char const *requestGrid) {
    if (grid == NULL) {
        return ;
    }
    struct json_object  *requestParsed = json_tokener_parse(requestGrid);
    struct json_object  *gridArray;
    struct json_object  *colorIa;

    json_object_object_get_ex(requestParsed, "grid", &gridArray);
    json_object_object_get_ex(requestParsed, "color_ia", &colorIa);
    initGridFromString(grid, gridArray, json_object_get_int(colorIa));
}

void                    initGridFromString(t_grid *grid, struct json_object *gridArray, e_value const iaColor) {
    struct json_object  *gridRow;
    size_t              x;
    struct json_object  *cellValue;

    if (grid == NULL || json_object_array_length(gridArray) != GRID_HEIGHT) {
        return ;
    }
    for (size_t y = 0; y < GRID_HEIGHT; y++) {
        gridRow = json_object_array_get_idx(gridArray, y);
        if (json_object_array_length(gridRow) != GRID_WIDTH) {
            return ;
        }
        for(x = 0; x < GRID_WIDTH; x++) {
            cellValue = json_object_array_get_idx(gridRow, x);
            grid->grid[y][x] = cellFactory(json_object_get_int(cellValue));
        }
    } 
    grid->iaColor = iaColor; 
}

void                    destructGrid(t_grid *grid)
{
    unsigned int        x;

    if (grid != NULL) {
        for(unsigned int y = 0; y < GRID_HEIGHT; y++) {
            for (x = 0; x < GRID_WIDTH; x++){
                free(grid->grid[y][x]);
                grid->grid[y][x] = NULL;
            }
            
        }
    }
}

void                    printGrid(t_grid const *grid)
{
        unsigned int        x;

    if (grid != NULL) {
        for(unsigned int y = 0; y < GRID_HEIGHT; y++) {
            for (x = 0; x < GRID_WIDTH; x++){
                printf("%s", printCell(grid->grid[y][x]));
            }
            printf("\n");
        }
    }
}
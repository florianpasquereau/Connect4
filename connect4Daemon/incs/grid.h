#ifndef GRID_H
# define GRID_H

# define GRID_HEIGHT 6u
# define GRID_WIDTH 7u
# define COUNT_LEFT_SHIFT GRID_WIDTH
# define COIN_LENGTH_END_GAME 4u
# define COIN_SEARCH_LENGTH COIN_LENGTH_END_GAME - 1

# include <json-c/json.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "cell.h"

/**
 * grid.c
*/

typedef struct          s_grid
{
    t_cell              grid[GRID_HEIGHT][GRID_WIDTH];
    e_value             iaColor;
    unsigned int        lastColumnPlayerCoin; // 0xffffffff if NULL else 0 <-> (GRID_WIDTH - 1)
    unsigned int        lastRowPlayerCoin;  // 0xffffffff if NULL else 0 <-> (GRID_HEIGHT- 1)
}                       t_grid;

bool                    initGrid(t_grid *grid, char const *requestGrid);
void                    printGrid(t_grid const *grid);
t_cell const            *gridGetCell(t_grid const *grid, unsigned int const y, unsigned int const x);
e_value const           *gridGetAiColor(t_grid const *grid);
unsigned int const      *gridGetLastColumnPayerCoin(t_grid const *grid);
unsigned int const      *gridGetLastRowPayerCoin(t_grid const *grid);

/**
 * gridMinMaxCell.c
*/
// typedef struct          s_scoring
// {
//     int                 line;
//     int                 column;
//     int                 leftTopRightBottom;
//     int                 rightTopLeftBottom;
// }                       t_scoring;

// typedef struct          s_scoringCell
// {
//     t_scoring           empty;
//     t_scoring           count;
// }                       t_scoringCell;

int                     scoringCell(t_grid const *grid, unsigned int const y, unsigned int const x);

/**
 * gridAnalyse.c
*/
bool                    cellWinner(t_grid const *grid, unsigned int const y, unsigned int const x);
unsigned int            countColumn(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellValue);
unsigned int            countLine(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellValue);
unsigned int            countLeftTopRightBottom(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellValue);
unsigned int            countRightTopLeftBottom(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellValue);

#endif
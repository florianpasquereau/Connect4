#ifndef GRID_H
# define GRID_H

# define GRID_HEIGHT 6u
# define GRID_WIDTH 7u
# define COUNT_LEFT_SHIFT GRID_WIDTH
# define COIN_LENGTH_END_GAME 4u
# define COIN_SEARCH_LENGTH COIN_LENGTH_END_GAME - 1u

# include <json-c/json.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

# include "cell.h"
# include "responseGrid.h"

/**
 * grid.c
*/

typedef struct          s_grid
{
    t_cell              grid[GRID_HEIGHT][GRID_WIDTH];  // grid
    e_value             iaColor;                        // cell value of the ia coin
    e_value             playerColor;                    // cell value of the player coin
    unsigned int        lastColumnPlayerCoin;           // 0xffffffff if NULL else 0 <-> (GRID_WIDTH - 1)
    unsigned int        lastRowPlayerCoin;              // 0xffffffff if NULL else 0 <-> (GRID_HEIGHT- 1)
    unsigned int        cellFilled;                     // count cell not empty
    bool                gameFinish;                     // true if the game is finish else false
    unsigned int        startColumns[GRID_WIDTH];       // store the first empty cell for each column
}                       t_grid;

bool                    initGrid(t_grid *grid, char const *requestGrid);
void                    printGrid(t_grid const *grid);
t_cell const            *gridGetCell(t_grid const *grid, unsigned int const y, unsigned int const x);
e_value const           *gridGetAiColor(t_grid const *grid);
unsigned int const      *gridGetLastColumnPayerCoin(t_grid const *grid);
unsigned int const      *gridGetLastRowPayerCoin(t_grid const *grid);
bool const              *gridGetGameFinish(t_grid const *grid) ;

/**
 * gridCountCoin.c
*/
typedef struct          s_counterCoin
{
    unsigned int        countEmpty;
    unsigned int        countCoin;
    unsigned int        countAlignedCoin;
    unsigned int        loop;
    e_value             cellValueExpected;
    t_grid const        *grid;
    unsigned int        y;
    unsigned int        x;
    bool                emptyFound;
    struct s_counterCoin *
                        (*f)(struct s_counterCoin *);
}                       t_counterCoin;

typedef struct          s_score
{
    unsigned int        score;
    bool                endGame;
}                       t_score;


bool                    initCounterCoin(t_counterCoin *counterCoin,t_grid const *grid, unsigned int const y, unsigned int const x, t_counterCoin *(*f)(t_counterCoin *));
t_counterCoin           *countCoin(t_counterCoin *counter);
t_score                 buildScoreFromCointerCoin(t_counterCoin const *counter);
// unsigned int            addAndbuildScoreFromCointerCoin(t_counterCoin const *counter1, t_counterCoin const *counter2);

/**
 * gridScoring.c
*/
// int                     scoringCell(t_grid const *grid, unsigned int const y, unsigned int const x);

/**
 * gridAnalyse.c
*/
bool                    cellWinner(t_grid const *grid, unsigned int const y, unsigned int const x);
t_score                 countColumn(t_grid const *grid, unsigned int const y, unsigned int const x);
t_score                 countLine(t_grid const *grid, unsigned int const y, unsigned int const x);
t_score                 countLeftTopRightBottom(t_grid const *grid, unsigned int const y, unsigned int const x);
t_score                 countRightTopLeftBottom(t_grid const *grid, unsigned int const y, unsigned int const x);

/**
 * gridMinMax.c
*/

bool                    findColumnIaSelected(t_grid *grid, unsigned char *columnIaSelected, char *message);

#endif
#include "../incs/grid.h"

static t_counterCoin    *countLineLeft(t_counterCoin *counter)
{
    counter->x--;
    return countCoin(counter);
}

static t_counterCoin    *countLineRight(t_counterCoin *counter)
{
    counter->x++;
    return countCoin(counter);
}

static t_counterCoin    *countTop(t_counterCoin *counter)
{
    counter->y--;
    return countCoin(counter);
}

static t_counterCoin    *countBottom(t_counterCoin *counter)
{
    counter->y++;
    return countCoin(counter);
}

static t_counterCoin    *countLeftTop(t_counterCoin *counter)
{
    counter->y--;
    counter->x--;
    return countCoin(counter);
}

static t_counterCoin    *countRightBottom(t_counterCoin *counter)
{
    counter->y++;
    counter->x++;
    return countCoin(counter);
}

static t_counterCoin    *countRightTop(t_counterCoin *counter)
{
    counter->y--;
    counter->x++;
    return countCoin(counter);
}

static t_counterCoin    *countLeftBottom(t_counterCoin *counter)
{
    counter->y++;
    counter->x--;
    return countCoin(counter);
}







bool                    cellWinner(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_score             line = countLine(grid, y, x);
    t_score             column = countColumn(grid, y, x);
    t_score             rightTopLeftBottom = countRightTopLeftBottom(grid, y, x);
    t_score             leftTopRightBottom = countLeftTopRightBottom(grid, y, x);

    // printf("grid[%u][%u]\n", y, x);
    // printf("countColumn : %d\n", column.score);
    // printf("countLine : %d\n", line.score);
    // printf("countRightTopLeftBottom : %d\n", rightTopLeftBottom.score);
    // printf("countLeftTopRightBottom : %d\n", leftTopRightBottom.score);
    // printGridChecker(grid, y, x);
    return (line.endGame || column.endGame || rightTopLeftBottom.endGame || leftTopRightBottom.endGame);
}


t_score                 countColumn(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_counterCoin       counter;

    initCounterCoin(&counter, grid,y, x, countBottom);
    if (y < GRID_HEIGHT && x < GRID_WIDTH) {
        countBottom(&counter);
        counter.f = countTop;
        counter.loop = 0;
        counter.x = x;
        counter.y = y;
        counter.emptyFound = false;
        countTop(&counter);
    }
    return buildScoreFromCointerCoin(&counter);
}

t_score                 countLine(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_counterCoin       counter;

    initCounterCoin(&counter, grid,y, x, countLineLeft);
    if (y < GRID_HEIGHT && x < GRID_WIDTH) {
        countLineLeft(&counter);
        counter.f = countLineRight;
        counter.loop = 0;
        counter.x = x;
        counter.y = y;
        counter.emptyFound = false;
        countLineRight(&counter);
    }
    return buildScoreFromCointerCoin(&counter);
}

t_score                 countLeftTopRightBottom(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_counterCoin       counter;

    initCounterCoin(&counter, grid,y, x, countLeftTop);
    if (y < GRID_HEIGHT && x < GRID_WIDTH) {
        countLeftTop(&counter);
        counter.f = countRightBottom;
        counter.loop = 0;
        counter.x = x;
        counter.y = y;
        counter.emptyFound = false;
        countRightBottom(&counter);
    }
    return buildScoreFromCointerCoin(&counter);
}

t_score                 countRightTopLeftBottom(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_counterCoin       counter;

    initCounterCoin(&counter, grid,y, x, countRightTop);
    if (y < GRID_HEIGHT && x < GRID_WIDTH) {
        countRightTop(&counter);
        counter.f = countLeftBottom;
        counter.loop = 0;
        counter.x = x;
        counter.y = y;
        counter.emptyFound = false;
        countLeftBottom(&counter);
    }
    return buildScoreFromCointerCoin(&counter);
}
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
    unsigned int        valueEnd = (0x1 << GRID_WIDTH) << (COIN_SEARCH_LENGTH);
    e_value const       *cellValue = cellgetValue(gridGetCell(grid, y, x));
    if (cellValue == NULL || cellValue == EMPTY) {
        false;
    }
    printf("grid[%u][%u]\n", y, x);
    printf("countColumn : %d\n", countColumn(grid, y, x));
    printf("countLine : %d\n", countLine(grid, y, x));
    printf("countRightTopLeftBottom : %d\n", countRightTopLeftBottom(grid, y, x));
    printf("countLeftTopRightBottom : %d\n", countLeftTopRightBottom(grid, y, x));
    return (countColumn(grid, y, x) > valueEnd || 
        countLine(grid, y, x) >= valueEnd || 
        countRightTopLeftBottom(grid, y, x) >= valueEnd || 
        countLeftTopRightBottom(grid, y, x) >= valueEnd);

}


unsigned int            countColumn(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_counterCoin       counter;

    initCounterCoin(&counter, grid,y, x, countBottom);
    countBottom(&counter);
    counter.f = countTop;
    counter.loop = 0;
    counter.x = x;
    counter.y = y;
    countTop(&counter);
    return buildScoreFromCointerCoin(&counter);
}

unsigned int            countLine(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_counterCoin       counter;

    initCounterCoin(&counter, grid,y, x, countLineLeft);
    countLineLeft(&counter);
    counter.f = countLineRight;
    counter.loop = 0;
    counter.x = x;
    counter.y = y;
    countLineRight(&counter);
    return buildScoreFromCointerCoin(&counter);
}

unsigned int            countLeftTopRightBottom(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_counterCoin       counter;

    initCounterCoin(&counter, grid,y, x, countLeftTop);
    countLeftTop(&counter);
    counter.f = countRightBottom;
    counter.loop = 0;
    counter.x = x;
    counter.y = y;
    countRightBottom(&counter);
    return buildScoreFromCointerCoin(&counter);
}

unsigned int            countRightTopLeftBottom(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_counterCoin       counter;

    initCounterCoin(&counter, grid,y, x, countRightTop);
    countRightTop(&counter);
    counter.f = countLeftBottom;
    counter.loop = 0;
    counter.x = x;
    counter.y = y;
    countLeftBottom(&counter);
    return buildScoreFromCointerCoin(&counter);

    t_counterCoin       counterLeftBottom;
    t_counterCoin       counterRightTop;

    initCounterCoin(&counterLeftBottom, grid,y, x, countLeftBottom);
    initCounterCoin(&counterRightTop, grid,y, x, countRightTop);
    return counterLeftBottom.countCoin | counterRightTop.countCoin | counterLeftBottom.countEmpty | counterRightTop.countEmpty;
}
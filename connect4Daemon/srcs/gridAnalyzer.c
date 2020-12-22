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
    unsigned int        valueEnd = (0x8 << GRID_WIDTH);
    e_value const       *cellValue = cellgetValue(gridGetCell(grid, y, x));
    if (cellValue == NULL || cellValue == EMPTY) {
        false;
    }
    printf("grid[%u][%u]\n", y, x);
    printf("countColumn : %x\n", countColumn(grid, y, x));
    printf("countLine : %x\n", countLine(grid, y, x));
    printf("countRightTopLeftBottom : %x\n", countRightTopLeftBottom(grid, y, x));
    printf("countLeftTopRightBottom : %x\n", countLeftTopRightBottom(grid, y, x));
    return (countColumn(grid, y, x) ^ valueEnd) == 0 || 
        (countLine(grid, y, x) ^ valueEnd) == 0 || 
        (countRightTopLeftBottom(grid, y, x) ^ valueEnd) == 0 || 
        (countLeftTopRightBottom(grid, y, x) ^ valueEnd) == 0;

}


unsigned int            countColumn(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_counterCoin       counterBottom;
    t_counterCoin       counterTop;

    initCounterCoin(&counterBottom, grid,y, x, countBottom);
    initCounterCoin(&counterTop, grid,y, x, countTop);
    return addAndbuildScoreFromCointerCoin(countBottom(&counterBottom), countTop(&counterTop));
}

unsigned int            countLine(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    /**
     * unsigned int        countEmpty;
    unsigned int        countCoin;
    unsigned int        loop;
    e_value             cellValueExpected;
    t_grid const        *grid;
    unsigned int        y;
    unsigned int        x;
    */
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
    t_counterCoin       counterLeftTop;
    t_counterCoin       counterRightBottom;

    initCounterCoin(&counterLeftTop, grid,y, x, countLeftTop);
    initCounterCoin(&counterRightBottom, grid,y, x, countRightBottom);
    return counterLeftTop.countCoin | counterRightBottom.countCoin | counterLeftTop.countEmpty | counterRightBottom.countEmpty;
}

unsigned int            countRightTopLeftBottom(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_counterCoin       counterLeftBottom;
    t_counterCoin       counterRightTop;

    initCounterCoin(&counterLeftBottom, grid,y, x, countLeftBottom);
    initCounterCoin(&counterRightTop, grid,y, x, countRightTop);
    return counterLeftBottom.countCoin | counterRightTop.countCoin | counterLeftBottom.countEmpty | counterRightTop.countEmpty;
}
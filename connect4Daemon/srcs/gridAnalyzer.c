#include "../incs/grid.h"

static unsigned int     countCoin(t_grid const *grid, 
    unsigned int const y, 
    unsigned int const x,
    e_value const *cellBaseValue,
    unsigned int const count,
    unsigned int (*f)(
        t_grid const *,
        unsigned int const,
        unsigned int const,
        e_value const *,
        unsigned int const
    ) 
)
{
    t_cell const        *cell;

    if (count >= COIN_SEARCH_LENGTH ||                              //if atleast 4 coins are aligned 
            cellBaseValue == NULL ||                                //if cellBaseValue is null
            (cell = gridGetCell(grid, y, x)) == NULL ||             //if cell is outside of the grid range
            (*cellgetValue(cell)) != (*cellBaseValue)) {            //if cellChecked do not have the same value than the base cell
        return count;
    }
    return f(grid, y, x, cellBaseValue, count + 1);
}








static unsigned int     countLineLeft(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellBaseValue, unsigned int const count)
{
    return countCoin(grid, y, x - 1, cellBaseValue, count, countLineLeft);

}

static unsigned int     countLineRight(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellBaseValue, unsigned int const count)
{
    return countCoin(grid, y, x + 1, cellBaseValue, count, countLineRight);
}

static unsigned int     countBottom(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellBaseValue, unsigned int const count)
{
    return countCoin(grid, y + 1, x, cellBaseValue, count, countBottom);
}

static unsigned int     countLeftTop(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellBaseValue, unsigned int const count)
{
    return countCoin(grid, y - 1, x - 1, cellBaseValue, count, countLeftTop);
}

static unsigned int     countRightBottom(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellBaseValue, unsigned int const count)
{
    return countCoin(grid, y + 1, x + 1, cellBaseValue, count, countRightBottom);
}

static unsigned int     countRightTop(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellBaseValue, unsigned int const count)
{
    return countCoin(grid, y - 1, x + 1, cellBaseValue, count, countRightTop);
}

static unsigned int     countLeftBottom(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellBaseValue, unsigned int const count)
{
    return countCoin(grid, y + 1, x - 1, cellBaseValue, count, countLeftBottom);
}







bool                    cellWinner(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    e_value const       *cellValue = cellgetValue(gridGetCell(grid, y, x));
    if (cellValue == NULL || cellValue == EMPTY) {
        false;
    }
    printf("grid[%u][%u]\n", y, x);
    printf("countColumn : %x\n", countColumn(grid, y, x, cellValue));
    printf("countLine : %x\n", countLine(grid, y, x, cellValue));
    printf("countRightTopLeftBottom : %x\n", countRightTopLeftBottom(grid, y, x, cellValue));
    printf("countLeftTopRightBottom : %x\n", countLeftTopRightBottom(grid, y, x, cellValue));
    return (countColumn(grid, y, x, cellValue) ^ 0x8) == 0 || 
        (countLine(grid, y, x, cellValue) ^ 0x8) == 0 || 
        (countRightTopLeftBottom(grid, y, x, cellValue) ^ 0x8) == 0 || 
        (countLeftTopRightBottom(grid, y, x, cellValue) ^ 0x8) == 0;

}


unsigned int            countColumn(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellValue)
{
    unsigned int        ret = 1;

    return ret << countBottom(grid, y, x, cellValue, 0);
}

unsigned int            countLine(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellValue)
{
    unsigned int        ret = 1;

    ret = ret << countLineLeft(grid, y, x, cellValue, 0);
    ret = ret << countLineRight(grid, y, x, cellValue, 0);
    return ret;
}

unsigned int            countLeftTopRightBottom(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellValue)
{
    unsigned int        ret = 1;

    ret = ret << countLeftTop(grid, y, x, cellValue, 0);
    ret = ret << countRightBottom(grid, y, x, cellValue, 0);
    return ret;
}

unsigned int            countRightTopLeftBottom(t_grid const *grid, unsigned int const y, unsigned int const x, e_value const *cellValue)
{
    unsigned int        ret = 1;

    ret = ret << countLeftBottom(grid, y, x, cellValue, 0);
    ret = ret << countRightTop(grid, y, x, cellValue, 0);
    return ret;
}
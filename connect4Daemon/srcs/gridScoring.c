#include "../incs/grid.h"

static int              scoringCellBuilder(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    unsigned int        ret = 0x80000000;
    unsigned int        tmp;

    ret = countColumn(grid, y, x);
    ret = (tmp = countLine(grid, y, x)) > ret ? tmp : ret;
    ret = (tmp = countLeftTopRightBottom(grid, y, x)) > ret ? tmp : ret;
    ret = (tmp = countRightTopLeftBottom(grid, y, x)) > ret ? tmp : ret;
    return (int)ret << GRID_WIDTH;
}

int                     scoringCell(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_cell const            *cell;
    int                     ret;
    e_value const           *cellValue;

    if ((cell = gridGetCell(grid, y, x)) == NULL || (*(cellValue = cellgetValue(cell))) == EMPTY) {
        return 0x80000000;
    }
    ret = scoringCellBuilder(grid, y, x);
    
    return (*cellgetValue(cell)) == grid->iaColor ? ret : ret * -1;
}
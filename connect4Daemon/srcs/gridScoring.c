#include "../incs/grid.h"

static unsigned int     scoringCellBuilder(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    t_score             ret, tmp;

    ret = countColumn(grid, y, x);
    tmp = countLine(grid, y, x);
    ret = tmp.score > ret.score ? tmp : ret;
    tmp = countLeftTopRightBottom(grid, y, x);
    ret = tmp.score > ret.score ? tmp : ret;
    tmp = countRightTopLeftBottom(grid, y, x);
    ret = tmp.score > ret.score ? tmp : ret;
    return ret.score;
}

unsigned int            scoringCell(t_grid const *grid, unsigned int const y, unsigned int const x)
{
    e_value const       *cellValue;

    if ((cellValue = cellgetValue(gridGetCell(grid, y, x))) == NULL) {
        return 0;
    }
    return scoringCellBuilder(grid, y, x);
}
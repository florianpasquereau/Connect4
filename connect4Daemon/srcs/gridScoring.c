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

long int                scoringCell(t_grid const *grid, unsigned int const y, unsigned int const x, unsigned int const deep)
{
    e_value const       *cellValue;
    unsigned int        score;

    if ((cellValue = cellgetValue(gridGetCell(grid, y, x))) == NULL) {
        return 0;
    }
    score = scoringCellBuilder(grid, y, x) << deep;
    return score;
}
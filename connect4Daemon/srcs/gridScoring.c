#include "../incs/grid.h"

// static t_score          scoringCellBuilder(t_grid const *grid, unsigned int const y, unsigned int const x)
// {
//     t_score             ret, tmp;

//     ret = countColumn(grid, y, x);
//     tmp = countLine(grid, y, x);
//     ret = tmp.score > ret.score ? tmp : ret;
//     tmp = countLeftTopRightBottom(grid, y, x);
//     ret = tmp.score > ret.score ? tmp : ret;
//     tmp = countRightTopLeftBottom(grid, y, x);
//     ret = tmp.score > ret.score ? tmp : ret;
//     ret.score = ret.score << GRID_WIDTH;
//     return (int);
// }

// int                     scoringCell(t_grid const *grid, unsigned int const y, unsigned int const x)
// {
//     t_cell const            *cell;
//     t_score                 ret;
//     e_value const           *cellValue;

//     if ((cell = gridGetCell(grid, y, x)) == NULL || (*(cellValue = cellgetValue(cell))) == EMPTY) {
//         return 0x80000000;
//     }
//     ret = scoringCellBuilder(grid, y, x);
    
//     return (*cellgetValue(cell)) == grid->iaColor ? ret.score : ret.score * -1;
// }
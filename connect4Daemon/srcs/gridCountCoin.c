#include "../incs/grid.h"

bool                    initCounterCoin(t_counterCoin *counterCoin,
        t_grid const *grid, 
        unsigned int const y, 
        unsigned int const x,
        t_counterCoin *(*f)(
            t_counterCoin *
        )
    )
{
    e_value const       *cellValue = cellgetValue(gridGetCell(grid, y, x));
    
    
    if (counterCoin == NULL) {
        return false;
    }
    memset(counterCoin, 0, sizeof(t_counterCoin));
    counterCoin->y = y;
    counterCoin->x = x;
    counterCoin->grid = grid;
    if (cellValue == NULL) {
        return false;
    }
    counterCoin->countCoin = 1u;
    counterCoin->countEmpty = 1u;
    counterCoin->countAlignedCoin = 1u;
    counterCoin->cellValueExpected = (*cellValue);
    counterCoin->f = f;
    return true;
}

t_counterCoin           *countCoin(t_counterCoin *counter)
{
    t_cell const        *cell = NULL;
    e_value const       *cellValue;

    if (counter == NULL || 
            counter->loop >= COIN_SEARCH_LENGTH ||                                              //stop the loop at the end max 4  
            (cell = gridGetCell(counter->grid, counter->y, counter->x)) == NULL) {              //if cell is outside of the grid range
        return counter;
    }
    if ((*(cellValue = cellgetValue(cell))) == counter->cellValueExpected) {
        counter->countCoin = counter->countCoin << 1;
        if (counter->emptyFound == false) {
            counter->countAlignedCoin ++;
        }
    } else if ((*cellValue) == EMPTY) {
        counter->countEmpty = counter->countEmpty << 1;
        counter->emptyFound = true;
    } else {
        return counter;
    }
    counter->loop++;
    return counter->f(counter);
}

t_score                 buildScoreFromCointerCoin(t_counterCoin const *counter)
{
    unsigned int        i;
    unsigned int        tmp;
    t_score             ret;

    ret.endGame = false;
    ret.score = 0x80000000;
    if (counter == NULL) {
        return ret;
    }
    for(i = 1, tmp = counter->countEmpty; tmp > 1; i++) {
        tmp = tmp >> 1;
    }
    for (tmp = counter->countCoin; tmp > 1; i++) {
        tmp = tmp >> 1;
    }
    ret.score = i >= COIN_LENGTH_END_GAME ? (counter->countCoin << GRID_WIDTH) + counter->countEmpty + counter->countAlignedCoin : counter->countCoin + counter->countEmpty + counter->countAlignedCoin;
    ret.endGame = counter->countAlignedCoin >= COIN_LENGTH_END_GAME ? true : false;
    return ret;
}

// unsigned int            addAndbuildScoreFromCointerCoin(t_counterCoin const *counter1, t_counterCoin const *counter2)
// {
//     t_counterCoin       counter;

//     counter.countCoin = counter1->countCoin > counter2->countCoin ? counter1->countCoin : counter2->countCoin;
//     counter.countEmpty = counter1->countEmpty > counter2->countEmpty ? counter1->countEmpty : counter2->countEmpty;
//     return buildScoreFromCointerCoin(&counter);
// }
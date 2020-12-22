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
    counterCoin->cellValueExpected = (*cellValue);
    counterCoin->f = f;
    return true;
}

t_counterCoin           *countCoin(t_counterCoin *counter)
{
    t_cell const        *cell = NULL;
    e_value const       *cellValue;

    if (counter == NULL || 
            counter->loop >= COIN_SEARCH_LENGTH ||                                              //if atleast 4 coins are aligned 
            (cell = gridGetCell(counter->grid, counter->y, counter->x)) == NULL) {              //if cell is outside of the grid range
        return counter;
    }
    if ((*(cellValue = cellgetValue(cell))) == counter->cellValueExpected) {
        counter->countCoin = counter->countCoin << 1;
    } else if ((*cellValue) == EMPTY) {
        counter->countEmpty = counter->countEmpty << 1;
    } else {
        return counter;
    }
    counter->loop++;
    return counter->f(counter);
}

unsigned int            buildScoreFromCointerCoin(t_counterCoin const *counter)
{
    unsigned int        i;
    unsigned int        tmp;

    if (counter == NULL) {
        return 0x80000000;
    }
    for(i = 1, tmp = counter->countEmpty; tmp > 1; i++) {
        tmp = tmp >> 1;
    }
    for (tmp = counter->countCoin; tmp > 1; i++) {
        tmp = tmp >> 1;
    }
    return i >= COIN_LENGTH_END_GAME ? (counter->countCoin << GRID_WIDTH) + counter->countEmpty : counter->countCoin + counter->countEmpty;

    return (counter->countCoin << GRID_WIDTH) + counter->countEmpty;
}

// unsigned int            addAndbuildScoreFromCointerCoin(t_counterCoin const *counter1, t_counterCoin const *counter2)
// {
//     unsigned int        countCoin, countEmpty;

//     if (counter1 == NULL || counter2 == NULL) {
//         return 0x80000000;
//     }
//     countCoin = counter1->countCoin | counter2->countCoin;
//     countEmpty = counter1->countEmpty | counter2->countEmpty;

//     return (countCoin & countEmpty) == 0xf ? (countCoin << GRID_WIDTH) + countEmpty : countEmpty;
// }
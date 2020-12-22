#ifndef TEST_MODE_H
# define TEST_MODE_H

# define MAX_BUFFER_TEST_SIZE 10000
# define BUFFER_ERROR_SIZE 100

# include <json-c/json.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

# include "grid.h"

typedef struct          s_testNode
{
    t_grid              grid;
    unsigned int        iTest;
    unsigned int        cellFilledCounter;
    unsigned int        coinAnalyseY;
    unsigned int        coinAnalyseX;
    unsigned int        countLine;
    unsigned int        countColumn;
    unsigned int        countLeftTopRightBottom;
    unsigned int        countRightTopLeftBottom;
    char                bufferError[BUFFER_ERROR_SIZE];
}                       t_testNode;


int                     testMode(int argc, char **argv);

#endif
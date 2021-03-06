#include "../incs/grid.h"

// static bool             printBuffer(char *buffer, ssize_t const bufferSize, ssize_t *bufferLength)
static bool             printBuffer(char *buffer, ssize_t *bufferLength)

{
    ssize_t             lengthWriten;
    bool                ret;

    lengthWriten = write(STDOUT_FILENO, buffer, *bufferLength);
    ret = lengthWriten == (*bufferLength);
    (*bufferLength) = 0;
    // memset(buffer, 0, bufferSize);
    buffer[(*bufferLength)] = '\0';
    return ret;
}      

static bool             addToBuffer(char *buffer, ssize_t const bufferSize, ssize_t *bufferLength, char const *txt){
    ssize_t              lenTxt;

    if (buffer == NULL || bufferLength == NULL || txt == NULL) {
        return false;
    }

    lenTxt = (ssize_t)strlen(txt);
    if ((*bufferLength) + lenTxt >= bufferSize - 1) {
        printBuffer(buffer, bufferLength);
    }
    strncat(buffer, txt, bufferSize - 1);
    (*bufferLength) += lenTxt;
    return true;
}

void                    printGrid(t_grid const *grid)
{
    unsigned int        x;
    char                buffer[BUFFER_SIZE] = "";
    ssize_t             currentLength = 0;

    if (grid != NULL) {
        for(unsigned int y = 0; y < GRID_HEIGHT; y++) {
            for (x = 0; x < GRID_WIDTH; x++){
                addToBuffer(buffer, BUFFER_SIZE, &currentLength, printCell(gridGetCell(grid, y, x)));
            }
            addToBuffer(buffer, BUFFER_SIZE, &currentLength, "\n");
        }
        addToBuffer(buffer, BUFFER_SIZE, &currentLength, "\n");
        printBuffer(buffer, &currentLength);
    }

}

void                    printGridChecker(t_grid const *grid, unsigned int const line, unsigned int const column)
{
    unsigned int        x;
    char                buffer[BUFFER_SIZE] = "";
    ssize_t             currentLength = 0;

    if (grid != NULL) {
        for(unsigned int y = 0; y < GRID_HEIGHT; y++) {
            for (x = 0; x < GRID_WIDTH; x++){
                if (y == line && x == column) {
                    addToBuffer(buffer, BUFFER_SIZE, &currentLength, printCellSelected(gridGetCell(grid, y, x)));
                } else {
                    addToBuffer(buffer, BUFFER_SIZE, &currentLength, printCell(gridGetCell(grid, y, x)));
                }
            }
            addToBuffer(buffer, BUFFER_SIZE, &currentLength, "\n");
        }
        addToBuffer(buffer, BUFFER_SIZE, &currentLength, "\n");
        printBuffer(buffer, &currentLength);
    }

}
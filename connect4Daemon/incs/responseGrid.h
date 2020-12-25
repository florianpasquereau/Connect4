#ifndef ANSWER_GRID_H
# define ANSWER_GRID_H

# define BUFFER_SIZE 2000
# define BUFFER_SIZE_MESSAGE 50

# include <stdbool.h>
# include <stdio.h>
# include <string.h>

typedef struct          s_answerGrid
{
    int                 columnIaSelected;
    double              timeSpend;
    bool                gameFinish;
    char                buffer[BUFFER_SIZE];
    bool                success;
    char                message[BUFFER_SIZE_MESSAGE];
}                       t_answerGrid;

void                    initAnswerGrid(t_answerGrid *answerGrid, 
        unsigned const char columnIaSelected, 
        double const timeSpend, 
        bool const gameFinish, 
        bool const success, 
        char const *message);
char                    *answerGridToJson(t_answerGrid *answerGrid);

#endif
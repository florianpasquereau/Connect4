#include "../incs/responseGrid.h"

void                    initAnswerGrid(t_answerGrid *answerGrid, unsigned const char columnIaSelected, double const timeSpend, bool const gameFinish)
{
    answerGrid->columnIaSelected = columnIaSelected;
    answerGrid->timeSpend = timeSpend;
    answerGrid->gameFinish = gameFinish;
}

char                    *answerGridToJson(t_answerGrid const *answerGrid)
{
    char                buffer[BUFFER_SIZE + 1];

    snprintf(buffer, BUFFER_SIZE + 1, "{\
            \"column_ia_selected\":%d,\
            \"time_spend\":%f,\
            \"game_finish\":%s\
        }",
        answerGrid->columnIaSelected,
        answerGrid->timeSpend,
        answerGrid->gameFinish == true ? "true" : "false"
    );
    return strdup(buffer);
}
#include "../incs/responseGrid.h"

void                    initAnswerGrid(t_answerGrid *answerGrid, unsigned const char columnIaSelected, double const timeSpend, bool const gameFinish)
{
    if (answerGrid == NULL) {
        return ;
    }
    answerGrid->columnIaSelected = columnIaSelected;
    answerGrid->timeSpend = timeSpend;
    answerGrid->gameFinish = gameFinish;
}

char                    *answerGridToJson(t_answerGrid *answerGrid)
{
    if (answerGrid == NULL) {
        return NULL;
    }
    snprintf(answerGrid->buffer, BUFFER_SIZE, "{\
            \"column_ia_selected\":%d,\
            \"time_spend\":%f,\
            \"game_finish\":%s\
        }",
        answerGrid->columnIaSelected,
        answerGrid->timeSpend,
        answerGrid->gameFinish == true ? "true" : "false"
    );
    return answerGrid->buffer;
}
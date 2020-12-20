#include "../incs/responseGrid.h"

void                    initAnswerGrid(t_answerGrid *answerGrid, 
        unsigned const char columnIaSelected, 
        double const timeSpend, 
        bool const gameFinish, 
        bool const success, 
        char const *message)
{
    if (answerGrid == NULL) {
        return ;
    }
    answerGrid->success = success;
    strncpy(answerGrid->message, message, BUFFER_SIZE_MESSAGE); 
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
            \"game_finish\":%s,\
            \"success\":%s,\
            \"message\":\"%s\"\
        }",
        answerGrid->columnIaSelected,
        answerGrid->timeSpend,
        answerGrid->gameFinish == true ? "true" : "false",
        answerGrid->success == true ? "true" : "false",
        answerGrid->message
    );
    return answerGrid->buffer;
}
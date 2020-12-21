#include "../incs/testMode.h"

static void             helper(char **argv) {
    fprintf(stderr, "%s <tests.json>\n", argv[0]);
    exit(EXIT_FAILURE);
}

static bool             initGridTest(struct json_object  *test, t_grid *grid)
{
    unsigned int        x;
    struct json_object  *gridRow;
    struct json_object  *gridJson;
    struct json_object  *cellValue;
    e_value             value;

    json_object_object_get_ex(test, "grid", &gridJson);
    for (unsigned int y = 0; y < GRID_HEIGHT; y++) {
        gridRow = json_object_array_get_idx(gridJson, y);
        if (json_object_array_length(gridRow) != GRID_WIDTH) {
            return false;
        }
        for(x = 0; x < GRID_WIDTH; x++) {
            cellValue = json_object_array_get_idx(gridRow, x);
            value = json_object_get_int(cellValue);
            if (cellSetValue((t_cell *)gridGetCell(grid, y, x), value) == false) {
                return false;
            }
            grid->cellFilled = value != EMPTY ? grid->cellFilled + 1 : grid->cellFilled;
        }
    }
    return true;
}

static bool             initTestNodeOtherValue(struct json_object *test, t_testNode *testNode) {
    struct json_object  *cellFilledCounter;
    struct json_object  *countLine;
    struct json_object  *countColumn;
    struct json_object  *countLeftTopRightBottom;
    struct json_object  *countRightTopLeftBottom;
    struct json_object  *coinAnalyse;
    struct json_object  *coinAnalyseY;
    struct json_object  *coinAnalyseX;

    json_object_object_get_ex(test, "cellFilledCounter", &cellFilledCounter);
    json_object_object_get_ex(test, "countLine", &countLine);
    json_object_object_get_ex(test, "countColumn", &countColumn);
    json_object_object_get_ex(test, "countLeftTopRightBottom", &countLeftTopRightBottom);
    json_object_object_get_ex(test, "countRightTopLeftBottom", &countRightTopLeftBottom);
    json_object_object_get_ex(test, "coinAnalyse", &coinAnalyse);
    json_object_object_get_ex(coinAnalyse, "y", &coinAnalyseY);
    json_object_object_get_ex(coinAnalyse, "x", &coinAnalyseX);
    testNode->cellFilledCounter = (unsigned int)json_object_get_int64(cellFilledCounter);
    testNode->countLine = (unsigned int)json_object_get_int64(countLine);
    testNode->countColumn = (unsigned int)json_object_get_int64(countColumn);
    testNode->countLeftTopRightBottom = (unsigned int)json_object_get_int64(countLeftTopRightBottom);
    testNode->countRightTopLeftBottom = (unsigned int)json_object_get_int64(countRightTopLeftBottom);
    testNode->coinAnalyseY = (unsigned int)json_object_get_int64(coinAnalyseY);
    testNode->coinAnalyseX = (unsigned int)json_object_get_int64(coinAnalyseX);
    return true;
}

static bool             initTestNode(struct json_object *test, t_testNode *testNode, unsigned int iTest)
{
    if (testNode == NULL) {
        return false;
    }
    memset(testNode, 0, sizeof(t_testNode));
    testNode->iTest = iTest + 1;
    if (!initGridTest(test, &testNode->grid)) {
        return false;
    }
    return initTestNodeOtherValue(test, testNode);
}

static bool             compareJsonToData(t_testNode *testNode) {
    bool                ret = true;
    unsigned int        counter;

    if (testNode->grid.cellFilled != testNode->cellFilledCounter) {
        snprintf(testNode->bufferError, BUFFER_ERROR_SIZE, "Test [%u] : Grid.cellField == \033[31m%u\033[0m expected : \033[31m%u\033[0m\n", testNode->iTest, testNode->grid.cellFilled, testNode->cellFilledCounter);
        perror(testNode->bufferError);
        ret = false;
    } else if ((counter = countLine(&testNode->grid, testNode->coinAnalyseY, testNode->coinAnalyseX)) != testNode->countLine) {
        snprintf(testNode->bufferError, BUFFER_ERROR_SIZE, "Test [%u] : countLine == \033[31m%d\033[0m expected : \033[31m%d\033[0m\n", testNode->iTest, counter, testNode->countLine);
        perror(testNode->bufferError);
        ret = false;
    }
    return ret;
}

static bool             executeTestLoop(struct json_object *test, unsigned int iTest) {
    t_testNode          testNode;

    if (test == NULL) {
        perror("TestLoop is NULL\n");
    }
    if (!initTestNode(test, &testNode, iTest)) {
        snprintf(testNode.bufferError, BUFFER_ERROR_SIZE, "Not possible to initGrid test[%d]\n", testNode.iTest);
        perror(testNode.bufferError);
    } else {
        return compareJsonToData(&testNode);
    }
    return false;
}

static bool             executeTest(struct json_object  *test) {
    struct json_object  *name, *tests;
    size_t              numberTests;

    if (test == NULL) {
        perror("Test is NULL\n");
        return false;
    }
    json_object_object_get_ex(test, "name", &name);
    json_object_object_get_ex(test, "tests", &tests);
    numberTests = json_object_array_length(tests);
    fprintf(stdout, "Starting : '%s' with %5lu test(s)\n", json_object_get_string(name), numberTests) ;
    for(size_t i = 0; i < numberTests; i++) {
        executeTestLoop(json_object_array_get_idx(tests, i), i);
    }
    fprintf(stdout, "End : '%s'\n", json_object_get_string(name)) ;
    return true;
}

int                     testMode(int argc, char **argv)
{
    FILE                *fd;
    char                buffer[MAX_BUFFER_TEST_SIZE];
    size_t              lengthRead, numberTests;
    struct json_object  *testParser, *tests;


    if (argc != 2) {
        helper(argv);
    } else if ((fd = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Not possible to open : %s\n", argv[1]);
        helper(argv);
    }
    lengthRead = fread(buffer, 1, MAX_BUFFER_TEST_SIZE - 1, fd);
    buffer[lengthRead] = '\0';
    testParser = json_tokener_parse(buffer);
    json_object_object_get_ex(testParser, "tests", &tests);
    numberTests = json_object_array_length(tests);
    for(size_t i = 0; i < numberTests; i++) {
        executeTest(json_object_array_get_idx(tests, i));
    }
    // printf("%s\nNumber Tests = %lu", buffer, numberTests);
    fclose(fd);
    return EXIT_SUCCESS;
}
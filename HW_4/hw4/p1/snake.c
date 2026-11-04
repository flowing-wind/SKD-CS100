#include "snake.h"
#include <stdlib.h>

bool snakeInit(Snake *snake, int rows, int cols, size_t length) {
    if (rows >= MIN_BOARD_SIZE && cols >= MIN_BOARD_SIZE && length >= 1 &&
        length <= (size_t)(cols - 2 * BOARD_WALL_THICKNESS)) {
        int headRow = rows / 2;
        int headCol = (int)length > cols / 2 ? (int)length : cols / 2;
        int tailCol = headCol - (int)length + 1;

        // Start from the tail
        SnakeNode *tail = malloc(sizeof *tail);
        if (tail == NULL) {
            return false;
        }
        tail->m_pos = (Coord){.m_row = headRow, .m_col = tailCol};
        tail->m_next = tail; // point to itself at first
        snake->m_head = tail;
        snake->m_length = 1;
        // insert other nodes
        for (int i = 0; i < (int)length - 1; i++) {
            SnakeNode *node = malloc(sizeof *node);
            if (node == NULL) {
                snakeDestroy(snake);
                return false;
            }
            node->m_pos = (Coord){.m_row = headRow, .m_col = tailCol + 1 + i};
            node->m_next = tail;          // the new head points to the tail
            snake->m_head->m_next = node; // the old head points to new node
            snake->m_head = node;         // node is the new head
            snake->m_length += 1;
        }
        snake->m_direction = DIR_RIGHT;
        snake->m_rows = rows;
        snake->m_cols = cols;

        return true;
    }

    return false;
}

static Direction newDirection(const Snake *snake, Direction requested) {
    // User-defined function, to determine the correct next direction
    Direction curDir = snake->m_direction;
    Direction oppositeDir = (Direction)((curDir + DIRECTION_COUNT / 2) % DIRECTION_COUNT);
    Direction correctDir = curDir;

    // (unsigned int)requested to ignore invalid direction values
    // follow the request as long as the dir is not the oppsite or length is 1
    if ((unsigned int)requested < DIRECTION_COUNT &&
        (snake->m_length == 1 || requested != oppositeDir)) {
        correctDir = requested;
    }

    return correctDir;
}

Coord snakeNextPosition(const Snake *snake, Direction requested) {
    Coord nextPos = snake->m_head->m_pos;
    Direction correctDir = newDirection(snake, requested);

    switch (correctDir) {
    case DIR_UP:
        nextPos.m_row -= 1;
        break;
    case DIR_RIGHT:
        nextPos.m_col += 1;
        break;
    case DIR_DOWN:
        nextPos.m_row += 1;
        break;
    case DIR_LEFT:
        nextPos.m_col -= 1;
        break;

    default:
        break;
    }
    return nextPos;
}

bool snakeContains(const Snake *snake, Coord pos) {
    const SnakeNode *node = snake->m_head; // do not change the snake
    if (node == NULL) {
        return false;
    }

    for (size_t i = 0; i < snake->m_length; i++) {
        if (pos.m_row == node->m_pos.m_row && pos.m_col == node->m_pos.m_col) {
            return true;
        }
        node = node->m_next;
    }

    return false;
}

StepResult snakeStep(Snake *snake, Direction requested, bool grow) {
    // STEP_WALL
    Coord next = snakeNextPosition(snake, requested);
    if (next.m_row < BOARD_WALL_THICKNESS || next.m_row >= snake->m_rows - BOARD_WALL_THICKNESS ||
        next.m_col < BOARD_WALL_THICKNESS || next.m_col >= snake->m_cols - BOARD_WALL_THICKNESS) {
        return STEP_WALL;
    }

    // STEP_SELF
    SnakeNode *tail = snake->m_head->m_next;
    bool enterOldTail = next.m_row == tail->m_pos.m_row && next.m_col == tail->m_pos.m_col;
    if (snakeContains(snake, next) && (grow || !enterOldTail)) {
        return STEP_SELF;
    }

    // MOVE
    Direction nextDir = newDirection(snake, requested);
    if (grow) {
        SnakeNode *node = malloc(sizeof *node);
        if (node == NULL) {
            return STEP_NO_MEMORY;
        }
        // add as the new head (where the original head would move to)
        node->m_pos = next;
        node->m_next = tail;
        snake->m_head->m_next = node; // the old head points to new node
        snake->m_head = node;         // node is the new head
        snake->m_length += 1;
    } else {
        // move tail to the new position and the head becomes the old tail
        tail->m_pos = next;
        snake->m_head = tail;
    }
    snake->m_direction = nextDir; // rewrite direction only after a success move

    return STEP_OK;
}

void snakeDestroy(Snake *snake) {
    if (snake->m_head != NULL) {
        SnakeNode *node = snake->m_head->m_next; // the tail of the snake
        snake->m_head->m_next = NULL;            // unlink the head and the tail

        while (node != NULL) {
            SnakeNode *next = node->m_next;
            free(node);
            node = next;
        }
    }

    *snake = (Snake){0};
}

unsigned int nextRandom(unsigned int seed) {
    static unsigned int state = RANDOM_INITIAL_SEED;
    if (seed > 0) {
        state = seed % RANDOM_MODULUS;
    }
    state = (RANDOM_MULTIPLIER * state + RANDOM_INCREMENT) % RANDOM_MODULUS;
    return state;
}

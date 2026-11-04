#include "flappy.h"

void advancePipes(Game *game, float dt) {
    for (int i = 0; i < PIPE_COUNT; i++) {
        game->m_pipes[i].m_x -= PIPE_SPEED * dt;
    }

    for (int i = 0; i < PIPE_COUNT; i++) {
        if (game->m_pipes[i].m_x + PIPE_WIDTH <= 0) {
            recyclePipe(game, i);
        }
    }
}

bool birdHitsObstacle(const Game *game) {
    Box bird = gameBirdBox(game);
    if (bird.m_y < 0 || (bird.m_y + bird.m_height) > FLOOR_Y) {
        return true;
    }

    for (int i = 0; i < PIPE_COUNT; i++) {
        Box upper = {
            .m_x = game->m_pipes[i].m_x,
            .m_y = 0,
            .m_width = PIPE_WIDTH,
            .m_height = game->m_pipes[i].m_gap_y,
        };
        Box lower = {
            .m_x = game->m_pipes[i].m_x,
            .m_y = game->m_pipes[i].m_gap_y + PIPE_GAP_HEIGHT,
            .m_width = PIPE_WIDTH,
            .m_height = FLOOR_Y - (game->m_pipes[i].m_gap_y + PIPE_GAP_HEIGHT),
        };
        if (boxesOverlap(bird, upper) || boxesOverlap(bird, lower)) {
            return true;
        }
    }
    return false;
}

int scorePassedPipes(Game *game) {
    int cnt = 0;
    for (int i = 0; i < PIPE_COUNT; i++) {
        if ((game->m_pipes[i].m_x + PIPE_WIDTH < BIRD_X) && game->m_pipes[i].m_scored == false) {
            cnt += 1;
            game->m_pipes[i].m_scored = true;
        }
    }
    game->m_score += cnt;
    return cnt;
}

unsigned int nextRandom(unsigned int seed) {
    static unsigned int state = RANDOM_INITIAL_SEED;
    if (seed > 0) {
        state = seed % RANDOM_MODULUS;
    }
    state = (RANDOM_MULTIPLIER * state + RANDOM_INCREMENT) % RANDOM_MODULUS;
    return state;
}

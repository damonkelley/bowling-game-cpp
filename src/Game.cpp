#include "game.h"

Game::Game() {
    currentRoll = 0;
    rolls.fill(0);
}

void Game::roll(int pins) {
    rolls[currentRoll++] = pins;
}

int Game::score() {
    int score = 0;
    int frameIndex = 0;
    for(int frame = 0; frame < 10; frame++) {
        if (isStrike(frameIndex)) {
            score += 10 + strikeBonus(frameIndex);
            frameIndex++;
        } else if (isSpare(frameIndex)) {
            score += 10 + spareBonus(frameIndex);
            frameIndex += 2;
        } else {
            score += rolls[frameIndex] + rolls[frameIndex + 1];
            frameIndex += 2;
        }
    }
    return score;
}

bool Game::isSpare(int frameIndex) {
    return 10 == rolls[frameIndex] + rolls[frameIndex + 1];
}

bool Game::isStrike(int frameIndex) {
    return 10 == rolls[frameIndex];
}

int Game::spareBonus(int frameIndex) {
    return rolls[frameIndex + 2];
}

int Game::strikeBonus(int frameIndex) {
    return rolls[frameIndex + 1] + rolls[frameIndex + 2];
}

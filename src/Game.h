#include <array>

class Game {
    std::array<int, 21> rolls;
    int currentRoll;

    bool isSpare(int frameIndex);
    bool isStrike(int frameIndex);

    int spareBonus(int frameIndex);
    int strikeBonus(int frameIndex);

    public:
    Game();
    void roll(int pins);
    int score();
};

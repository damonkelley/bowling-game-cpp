#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Game.h"

void rollMany(Game& game, int times, int pins) {
    for(int i=0; i<times; i++) {
        game.roll(pins);
    }
}

void rollSpare(Game& game) {
    game.roll(5);
    game.roll(5);
}

SCENARIO( "A Bowling Game" ) {
    GIVEN("A game") {
        Game game = Game();

        WHEN("it is a gutter game") {
            rollMany(game, 20, 0);

            THEN("the score is zero") {
                REQUIRE(game.score() == 0);
            }
        }
        WHEN("it has one pin per frame") {
            rollMany(game, 20, 1);

            THEN("the score is zero") {
                REQUIRE(game.score() == 20);
            }
        }
        WHEN("it has a spare") {
            rollSpare(game);
            game.roll(3);
            rollMany(game, 17, 0);

            THEN("the score is zero") {
                REQUIRE(game.score() == 16);
            }
        }
        WHEN("it has a strike") {
            game.roll(10);
            game.roll(3);
            game.roll(4);
            rollMany(game, 16, 0);

            THEN("the score is zero") {
                REQUIRE(game.score() == 24);
            }
        }

        WHEN("it is a perfect game") {
            rollMany(game, 12, 10);

            THEN("the score is zero") {
                REQUIRE(game.score() == 300);
            }
        }
    }
}

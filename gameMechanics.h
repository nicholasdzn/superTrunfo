#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include "CardsQueue.h"
#include "Player.h"
#include "Cards.h"

class Game {
    Player player1, player2;
    public:
        Game(Player player1, Player player2);
        void Round();
        bool HasGame();

};

#endif
#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include "CardsQueue.h"
#include "Player.h"
#include "Cards.h"

class Game {
    Player player1, player2;
    public:
        Game(Player player1, Player player2);
        bool Turn();
        bool HasGame();
        void InitTurn();
        Player WhoWinsTurn();
        Player NormalRule();
        Player SuperTrunfuRule();
        void SetDeckOfPlayers();
        void SetChoiceAttributes();
};

#endif
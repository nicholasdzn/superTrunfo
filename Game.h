#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include "CardsQueue.h"
#include "Cards.h"
#include "Player.h"
#include "AttributeCards.h"

class Game {
    Player player1, player2;
    Player playerWins;
    AttributeCards attrChoicePlayer1, attrChoicePlayer2;
    Cards currentCardPlayer1, currentCardPlayer2;
    Player NormalRule();
    Player SuperTrunfuRule();
    Player WhoWinsTurn();
    void InitTurn();
    void SetDeckOfPlayers(Player player);
    public:
        Game(Player player1, Player player2);
        bool Turn();
        bool HasGame();
        void SetChoiceAttributes(AttributeCards attr1, AttributeCards attr2);
        Player GetPlayerWinsTurn();
};

#endif
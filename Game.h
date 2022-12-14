#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include "CardsQueue.h"
#include "Cards.h"
#include "Player.h"
#include "AttributeCards.h"

class Game {
    Player *player1, *player2;
    Player *playerWins;
    AttributeCards attrChoicePlayer;
    Cards currentCardPlayer1, currentCardPlayer2;
    Player* NormalRule();
    Player* SuperTrunfuRule();
    void SetDeckOfPlayers();
    void PrintInfoCardOfPlayer(Cards card);
    public:
        Game(Player *player1, Player *player2);
        ~Game();
        bool Turn();
        bool HasGame();
        void SetChoiceAttributes(AttributeCards attribute);
        Player GetPlayerWinsTurn();
        void PrintInfoCards(Player *player);
        bool HasSuperTrunfuInTurn();
        static void GameRules();
        void InitTurn();
        void PrintPlacar();
};

#endif
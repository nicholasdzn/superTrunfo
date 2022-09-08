#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "CardsQueue.h"
#include "structCards.h"

class Player {
    CardsQueue cards;

    public:
        string nome;
        Player(string _Nome);
        ~Player();
        void InsertEndCards(Cards cards);
        void Append(Cards card);
        Cards RemoveTopCards();
        Cards GetTopCards();
        bool HasCards();

        int SelectAttribute();
        double GetValueAttributeOfCards(Cards card, int attribute); 
};

#endif
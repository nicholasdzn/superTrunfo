#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "CardsQueue.h"
#include "structCards.h"

class Player {
    string nome;
    CardsQueue cards;

    public:
        Player();
        ~Player();
        void InsertEndCards(Cards cards);
        Cards RemoveTopCards();
        Cards GetTopCards();
        bool HasCards();
        int SelectAttribute();
        double GetValueAttributeOfCards(Cards card, int attribute); 
}

#endif
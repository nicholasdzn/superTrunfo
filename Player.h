#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "CardsQueue.h"
#include "Cards.h"
#include "AttributeCards.h"

class Player {
    std::string nome;
    CardsQueue cards;

    public:
        Player();
        Player(std::string nome);
        ~Player();
        void InsertCardsOnDeck(Cards cards);
        Cards RemoveTopCards();
        Cards CurrentCard();
        bool HasCards();
        double GetValueAttributeOfCurrentCards(AttributeCards attribute);
        std::string GetNome();
};

#endif
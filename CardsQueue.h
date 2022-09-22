#ifndef CARDSQUEUE_H
#define CARDSQUEUE_H

#include <string>
#include <iostream>
#include <stddef.h>
#include "Cards.h"

struct CardsElement {
    Cards card;
    CardsElement *next;
};

typedef struct CardsElement CardsElement;

class CardsQueue {
    CardsElement *head;
    CardsElement *tail;
    int size;
    bool full;

    public:
        CardsQueue();
        ~CardsQueue();
        void Append(Cards value);
        Cards Serve();
        bool Empty();
        bool Full();
        void Clear();
        int Size();
        Cards Front();
        Cards Rear();
};

#endif
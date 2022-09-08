#ifndef CARDSQUEUE_H
#define CARDSQUEUE_H

#include <stddef.h>
#include <stdbool.h>
#include <string>
#include "structCards.h"
#include <iostream>

struct CardsElement {
    Cards card;
    Cards value;
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
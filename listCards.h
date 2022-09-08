#include <iostream>
#include "structCards.h"
#include "CardsQueue.h"
using namespace std;

class ListCards{
    public:
        ListCards();
        ~ListCards();
        void Insert(int x);
        void Delete(int p, int &x);
        bool Empty();
        bool Full();
    private:
        void SetPosition(int p, CardsElement &current);
        int count = 0;
        int p = 1;
        struct Node{
            int Entry;
            Node *next;
        };
        typedef Node *NodePointer;
        NodePointer *head;
};
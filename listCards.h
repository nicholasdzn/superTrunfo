#include <iostream>
#include "Cards.h"
#include "CardsQueue.h"
using namespace std;

class ListCards{
    public:
        ListCards();
        ~ListCards();
        void Insert(int p,int x);
        void Delete(int p, int &x);
        bool Empty();
        bool Full();
    private:
        int count = 0;
        int p = 1;
        struct Node{
            int Entry;
            Node *next;
        };
        typedef Node *ListPointer;
        ListPointer head;
        int count;
        void SetPosition(int p, ListPointer &current);
};
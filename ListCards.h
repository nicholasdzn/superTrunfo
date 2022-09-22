#include "Cards.h"

struct Node{
    Cards cards;
    Node *next;
};
typedef Node *ListPointer;

class ListCards{
    public:
        ListCards();
        ~ListCards();
        void Insert(int p, Cards x);
        void Delete(int p, Cards &x);
        bool Empty();
        bool Full();
        void GetPosition(int p, ListPointer &current);
        int Count();
    private:
        int count = 0;
        ListPointer head;
};
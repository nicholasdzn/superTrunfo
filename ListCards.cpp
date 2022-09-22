#include "listCards.h"
using namespace std;

ListCards::ListCards() {
    head = NULL;
}

ListCards::~ListCards() {
    Cards c;
    for (int i = count; i > 0; i--) {
        Delete(i, c);
    }
}

bool ListCards::Full(){
    return false;
}

bool ListCards::Empty(){
    return (head == NULL); 
}

void ListCards::Insert(int p, Cards x){
    ListPointer NewNode, current;
    NewNode = new Node;
    NewNode->cards = x;
    if(p == 1){ 
        NewNode->next = head;
        head = NewNode;
    }
    else{ 
        GetPosition(p-1, current);
        NewNode->next = current->next;
        current->next = NewNode;
    }
    
    count++;
}

void ListCards::GetPosition(int p, ListPointer &current){ 
    int i;
    current = head;
    for(i=2; i<=p; i++) {
        current = current->next;
    }
} 

void ListCards::Delete(int p, Cards &x){
    ListPointer Node, current;
    
    if(p == 1){ 
        Node = head;
        head = Node->next;
    }
    else{ 
        GetPosition(p-1,current);
        Node = current->next;
        current->next = Node->next;
    }

    x = Node->cards;
    delete Node;
    count = count - 1;
}

int ListCards::Count() {
    return count;
}
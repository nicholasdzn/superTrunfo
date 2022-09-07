#include <iostream>
#include "listCards.h"
using namespace std;

bool ListCards::Full(){
    return false;
}

bool ListCards::Empty(){
    return (head == NULL); 
}

void ListCards::Insert(int x){
    Node NewNode, current;
    NewNode = new Node;
    NewNode->Entry = x;

    if(p == 1){ 
        NewNode->next = head;
        head = NewNode;
    }
    else{ 
        SetPosition(p-1,current);
        NewNode->next = current->next;
        current->next = NewNode;
    }
    
    count++;
}

void List::SetPosition(int p, ListPointer &current){ 
    int i;
    current = head;
    for(i=2; i<=p; i++)
    current = current->NextNode;
} 

void ListCards::Delete(int &x){
    Node Node, current;
    if(p == 1)
    { Node = head;
    head = Node->next;
    }
    else
    { SetPosition(p-1,current);
    Node = current->next;
    current->next = Node->next;
    }
    x = Node->Entry;
    delete Node;
    count = count - 1;
}
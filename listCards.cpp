#include <iostream>
#include "listCards.h"
using namespace std;

/*
    precisa de ajustes para se adequar ao jogo
*/


bool ListCards::Full(){
    return false;
}

bool ListCards::Empty(){
    return (head == NULL); 
}

void ListCards::Insert(int x){
    NodePointer NewNode, current;
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

void ListCards::SetPosition(int p, ListPointer &current){ 
    int i;
    current = head;
    for(i=2; i<=p; i++)
    current = current->NextNode;
} 

void ListCards::Delete(int p, int &x){
    NodePointer Node, current;
    if(p == 1){ 
        Node = head;
        head = NodePointer->next;
    }
    else{ 
        SetPosition(p-1,current);
        Node = current->next;
        current->next = Node->next;
    }
    x = Node->Entry;
    delete Node;
    count = count - 1;
}
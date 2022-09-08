#include "CardsQueue.h"

CardsQueue::CardsQueue() {
    head = NULL;
    tail = NULL;
    size = 0;
    full = false;
}
CardsQueue::~CardsQueue() {
    Clear();
}
void CardsQueue::Append(Cards value) {
    CardsElement *temp = tail;
    tail = new CardsElement;
    if (tail == NULL) {
        full = true;
        return;
    }
    
    tail->value = value;
    if (temp != NULL) {
        temp->next = tail;
    }

    if (Empty()) {
        head = tail;
    }
    size++;
}
Cards CardsQueue::Serve () {
    if (Empty()) {
        std::cout << "Fila vazia, impossivel deletar" << std::endl;
        abort();
    }
    CardsElement *temp = head->next;
    Cards tempValue = head->value;
    delete head;
    head = temp;
    size--;
    return tempValue;
}
bool CardsQueue::Empty () {
    return size == 0;
}
bool CardsQueue::Full () {
    return full;
}
void CardsQueue::Clear () {
    while (!Empty())
        Serve();
}
int CardsQueue::Size () {
    return size;
}
Cards CardsQueue::Front() {
    return head->value;
}
Cards CardsQueue::Rear() {
    return tail->value;
}
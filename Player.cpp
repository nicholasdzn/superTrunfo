#include "Player.h"
#include <iostream>

Player::Player(string _Nome) {
    nome = _Nome;
}
Player::~Player() {
    cards.Clear();
}
void Player::InsertEndCards(Cards cards) {
    cards.Append(cards);
}
Cards Player::RemoveTopCards() {
    return cards.Serve();
}
Cards Player::GetTopCards() {
    return cards.Front();
}
bool Player::HasCards() {
    return cards.Count() == 0;
}
int Player::SelectAttribute() {
    int option;
    std::cout << nome << " selected the attribute: ";
    std::cin >> option;
    return option;
}
double Player::GetValueAttributeOfCards(Cards card, int attribute) {
    switch (attribute) {
        case AttributeCards::CURB_WEIGHT:
            return card.curbWeight;
        break;
        case AttributeCards::ENGINE_SIZE:
            return card.engineSize;
        break;
        case AttributeCards::HORSE_POWER:
            return card.horsePower;
        break;
        case AttributeCards::PRICE:
            return card.price;
        break;
    }
}
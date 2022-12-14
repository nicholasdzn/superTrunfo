#include "Player.h"

Player::Player(){}
Player::Player(std::string _nome) {
    nome = _nome;
}
Player::~Player() {
}
void Player::InsertCardsOnDeck(Cards _cards) {
    cards.Append(_cards);
}
Cards Player::RemoveTopCards() {
    return cards.Serve();
}
Cards Player::CurrentCard() {
    return cards.Front();
}
bool Player::HasCards() {
    return cards.Size() > 0;
}
int Player::GetValueAttributeOfCurrentCards(AttributeCards attribute) {
    Cards card = CurrentCard();
    int value;
    switch (attribute) {
        case AttributeCards::CURB_WEIGHT:
            value = card.curbWeight;
        break;
        case AttributeCards::ENGINE_SIZE:
            value = card.engineSize;
        break;
        case AttributeCards::HORSE_POWER:
            value = card.horsePower;
        break;
        case AttributeCards::PRICE:
            value = card.price;
        break;
    }
    return value;
}
std::string Player::GetNome () {
    return nome;
}
void Player::Clear() {
    cards.Clear();
}
int Player::SizeOfDeck() {
    return cards.Size();
}
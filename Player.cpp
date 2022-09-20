#include "Player.h"

Player::Player(std::string _nome) {
    nome = _nome;
}
Player::~Player() {
    cards.Clear();
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
    return cards.Size() == 0;
}
double Player::GetValueAttributeOfCurrentCards(AttributeCards attribute) {
    Cards card = CurrentCard();
    double value;
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
            value = retunr card.price;
        break;
    }
    return value;
}
std::string Player::GetNome () {
    return nome;
}
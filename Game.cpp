#include "Game.h"

using namespace std;

Game::Game(Player p1, Player p2){
    player1 = p1;
    player2 = p2;
}

bool Game::Turn() {   
    if (!HasGame()) {
        return false;
    }
    InitTurn();
    playerWins = WhoWinsTurn();
    SetDeckOfPlayers(playerWins);
    return true;
}

bool Game::HasGame () {
    return player1.HasCards() && player2.HasCards();
}

void Game::InitTurn () {
    currentCardPlayer1 = player1.CurrentCard();
    currentCardPlayer2 = player2.CurrentCard();
}

Player Game::WhoWinsTurn () {
    if (HasSuperTrunfuInTurn())
        return SuperTrunfuRule();

    return NormalRule();
}

Player Game::NormalRule () {
    double attr1 = player1.GetValueAttributeOfCurrentCards(attrChoicePlayer);
    double attr2 = player2.GetValueAttributeOfCurrentCards(attrChoicePlayer);

    if (attr1 > attr2) {
        return player1;
    }else {
        return player2;
    }
}

Player Game::SuperTrunfuRule () {
    bool bothAreSuperTrunfu = currentCardPlayer1.IsSuperTrunfu() && currentCardPlayer2.IsSuperTrunfu();

    if (bothAreSuperTrunfu) {
        if (currentCardPlayer1.GroupSuperTrunfu() > currentCardPlayer2.GroupSuperTrunfu()) {
            return player1;
        }else {
            return player2;
        }
    }

    if (currentCardPlayer1.IsSuperTrunfu()) {
        return player1;
    }else {
        return player2;
    }
}

void Game::SetDeckOfPlayers (Player player) {
    player.InsertCardsOnDeck(player1.RemoveTopCards());
    player.InsertCardsOnDeck(player2.RemoveTopCards());
}

void Game::SetChoiceAttributes (AttributeCards currentAttribute) {
    attrChoicePlayer = currentAttribute;
}

Player Game::GetPlayerWinsTurn() {
    return playerWins;
}

bool Game::HasSuperTrunfuInTurn () {
    return currentCardPlayer1.IsSuperTrunfu() || currentCardPlayer2.IsSuperTrunfu();
}

void Game::PrintInfoCards () {
    PrintInfoCardOfPlayer(player1.CurrentCard());
    PrintInfoCardOfPlayer(player2.CurrentCard());
}

void Game::PrintInfoCardOfPlayer (Cards card) {
    std::cout << "===========================" << std::endl;
    std::cout << "model: " << card.model << std::endl;
    std::cout << "weight: " << card.curbWeight << std::endl;
    std::cout << "engine size: " << card.engineSize << std::endl;
    std::cout << "horse power: " << card.horsePower << std::endl;
    std::cout << "price: " << card.price << std::endl;
    std::cout << "group: " << card.group << std::endl;
}
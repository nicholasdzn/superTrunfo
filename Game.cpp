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

void Game::GameRules(){
    std::cout << "O jogo é todo baseado em comparar as cartas que você possui com as do seu adversário (no caso o computador)." << std::endl; 
    std::cout << "Para que sua carta vença, o atributo (ou característica) escolhido precisa ter valor maior do que a carta do seu adversário." << std::endl;
    std::cout << "Quando sua carta vence, você ganha a carta do seu adversário. Em seguida,coloca ambas no fim do seu deck" << std::endl;
    std::cout << "============================================================================================================================" << std::endl;
    std::cout << "1. Embaralham-se as 32 cartas e dividem-se em dois decks (um para cada jogador –P1 e P2)" << std::endl;
    std::cout << "2. É retirada a carta do topo do deck de P1 e P2." << std::endl;
    std::cout << "3. Escolhe-se o atributo que vai ser comparado e verifica-se quem venceu." << std::endl;
    std::cout << "4. O vencedor recebe a carta do oponente e a coloca no final do seu deck, seguida da carta vencedora." << std::endl;
    std::cout << "5. Repete-se os passos 2 a 4 até que um dos jogadores fique com o deck vazio." << std::endl;
}
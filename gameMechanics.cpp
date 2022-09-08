#include "gameMechanics.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Game::Game(Player p1, Player p2){
    player1 = p1;
    player2 = p2;
};

void Game::Round() {
    
    if (!HasGame()) {
        if (player1.HasCards()) {
            cout << "Player 1: " << player1.nome << "Wins !!!!";
        }else {
            cout << "Player 2: " << player2.nome << "Wins !!!!";
        }
        cout << "End game" << endl;
        abort();
    }
    
    Cards cards_player1 = player1.GetTopCards();
    Cards cards_player2 = player2.GetTopCards();

    int opt1 = cards_player1.SelectAttribute();
    int opt2 = cards_player2.SelectAttribute();

    double value_attr1 = cards_player1.GetValueAttributeOfCards(cards_player1, opt1);
    double value_attr2 = cards_player2.GetValueAttributeOfCards(cards_player2, opt2);

    Cards card_of_player2 = player2.RemoveTopCards();
    Cards card_of_player1 = player1.RemoveTopCards();

    if (cards_player1.isSuperTrunfo) {
        cout << "Player " << player1.nome << " wins the round" << endl;
        player1.Append(card_of_player2);
        player1.Append(card_of_player1);
    }else if (cards_player2.isSuperTrunfo) {
        cout << "Player " << player2.nome << " wins the round" << endl;
        player2.Append(card_of_player2);
        player2.Append(card_of_player1);
    }else if (cards_player1.isSuperTrunfo && card_of_player2.isSuperTrunfo) {
        if (cards_player1.group[1] > card_of_player2.group[2]) {
            cout << "Player " << player1.nome << " wins the round" << endl;
            player1.Append(card_of_player2);
            player1.Append(card_of_player1);
        }else {
            cout << "Player " << player2.nome << " wins the round" << endl;
            player2.Append(card_of_player2);
            player2.Append(card_of_player1);
        }
    }

    if (value_attr1 > value_attr2) {
        cout << "Player " << player1.nome << " wins the round" << endl;
        player1.Append(card_of_player2);
        player1.Append(card_of_player1);
    }else if (value_attr2 > value_attr1) {
        cout << "Player " << player2.nome << " wins the round" << endl;
        player2.Append(card_of_player2);
        player2.Append(card_of_player1);
    }else {
        cout << "Something is wrong, nobody wins '-'" << endl;
        cout << "I'm not feeling i can't continue with game" << endl;
        abort();
    }



}

bool Game::HasGame () {
    return player1.HasCards() && player2.HasCards();
} 
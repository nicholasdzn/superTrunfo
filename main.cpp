#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
#include <time.h>
#include "Cards.h"
#include "Player.h"
#include "ListCards.h"
#include "Game.h"
#include "AttributeCards.h"

using namespace std;


Cards FactoryCard (
    string model,
    int curbWeight,
    int engineSize,
    int horsePower,
    int price,
    string group
) {
    Cards cards;
    cards.model = model;
    cards.curbWeight = curbWeight;
    cards.engineSize = engineSize;
    cards.horsePower = horsePower;
    cards.price = price;
    cards.group = group;
    cards.SetSuperTrunfu(group);
    return cards;
}


void PrintInfoCardOfPlayer (Cards card) {
    cout << "===========================" << endl;
    cout << "model: " << card.model << endl;
    cout << "weight: " << card.curbWeight << endl;
    cout << "engine size: " << card.engineSize << endl;
    cout << "horse power: " << card.horsePower << endl;
    cout << "price: " << card.price << endl;
    cout << "group: " << card.group << endl;
}

AttributeCards GetAttribute(int attribute) {
    switch (attribute) {
        case 0:
            return AttributeCards::CURB_WEIGHT;
        break;
        case 1:
            return AttributeCards::ENGINE_SIZE;
        break;
        case 2:
            return AttributeCards::HORSE_POWER;
        break;
        case 3:
            return AttributeCards::PRICE;
        break;
        default:
            cout << "opcao invalida" << endl;
            abort();
    }
}

int main (void) {
    srand(time(NULL));
    Player p1("player");
    Player p2("computer");
    ListCards list;

    string namefile = "cards.csv";
    ifstream GameIn(namefile, ios::in);

    string model;
    string curbWeight;
    string engineSize;
    string horsePower;
    string price;
    string group;

    int positionList = 1;

     while(!GameIn.eof()){
        getline(GameIn,model,',');
        getline(GameIn,curbWeight,',');
        getline(GameIn,engineSize,',');
        getline(GameIn,horsePower,',');
        getline(GameIn,price,',');
        getline(GameIn,group,'\n');

        Cards aux = FactoryCard(model, stoi(curbWeight), stoi(engineSize), 
                                stoi(horsePower), stoi(price), group);
        list.Insert(positionList, aux);
        positionList++;
    }

    Game game(p1,p2);
    Cards card;
    int decideQualPlayer = 0;

    while (!list.Empty()) {
        list.Delete((rand() % list.Count()) + 1, card);
        if (decideQualPlayer % 2 == 0) {
            p1.InsertCardsOnDeck(card);
        }else {
            p2.InsertCardsOnDeck(card);
        }
        decideQualPlayer++;
    }
    AttributeCards attributePlayer, attributeComputer;
    int attributeTemp;
    Player playerWins;
    while(game.HasGame()) {
        PrintInfoCardOfPlayer(p1.CurrentCard());
        PrintInfoCardOfPlayer(p2.CurrentCard());
        cout << "Escolha o atributo: " << endl;
        cin >> attributeTemp;
        attributePlayer = GetAttribute(attributeTemp);
        attributeComputer = GetAttribute((rand() % 4) + 1);
        game.SetChoiceAttributes(attributePlayer, attributeComputer);
        game.Turn();
        playerWins = game.GetPlayerWinsTurn();
        cout <<  "Ganhou: " << playerWins.GetNome() << endl;
    }
    // cout << "PLAYER 1: " << endl;
    // while (p1.HasCards()) {
    //     card = p1.RemoveTopCards();
    //     cout << "===========================" << endl;
    //     cout << "model: " << card.model << endl;
    //     cout << "weight: " << card.curbWeight << endl;
    //     cout << "engine size: " << card.engineSize << endl;
    //     cout << "horse power: " << card.horsePower << endl;
    //     cout << "price: " << card.price << endl;
    //     cout << "group: " << card.group << endl;
    // }

    // cout << "PLAYER 2: " << endl;
    // while (p2.HasCards()) {
    //     card = p2.RemoveTopCards();
    //     cout << "===========================" << endl;
    //     cout << "model: " << card.model << endl;
    //     cout << "weight: " << card.curbWeight << endl;
    //     cout << "engine size: " << card.engineSize << endl;
    //     cout << "horse power: " << card.horsePower << endl;
    //     cout << "price: " << card.price << endl;
    //     cout << "group: " << card.group << endl;
    // }


    // ListPointer tempList;
    // for (int i = 1; i <= list.Count(); i++) {
    //     list.GetPosition(i, tempList);
    //     card = tempList->cards;
    //     cout << "===========================" << endl;
    //     cout << "model: " << card.model << endl;
    //     cout << "weight: " << card.curbWeight << endl;
    //     cout << "engine size: " << card.engineSize << endl;
    //     cout << "horse power: " << card.horsePower << endl;
    //     cout << "price: " << card.price << endl;
    //     cout << "group: " << card.group << endl;
    // }

    return 0;
}
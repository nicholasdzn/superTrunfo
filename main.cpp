#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
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

AttributeCards GetAttribute(int attribute) {
    switch (attribute) {
        case 1:
            return AttributeCards::CURB_WEIGHT;
        break;
        case 2:
            return AttributeCards::ENGINE_SIZE;
        break;
        case 3:
            return AttributeCards::HORSE_POWER;
        break;
        case 4:
            return AttributeCards::PRICE;
        break;
        default:
            cout << "opcao invalida" << endl;
            abort();
    }
}

void StartGame(ListCards &list){
    Player p1("player"), p2("Computer");
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

    int attributeTemp;
    Player playerWins;
    bool vezPlayer = true;
    Game game(&p1,&p2);

    while(game.HasGame()) {
        if (vezPlayer) {
            cout << "Turno jogador!" << endl;
        }else {
            cout << "Turno computador!" << endl;
        }
        game.PrintPlacar();
        game.InitTurn();
        game.PrintInfoCards(&p1);

        if (game.HasSuperTrunfuInTurn()) {
            game.Turn();
            playerWins = game.GetPlayerWinsTurn();
            cout <<  "Ganhou: " << playerWins.GetNome() << endl;
            cout << "============================" << endl;
            vezPlayer = !vezPlayer;
            continue;
        }
        if (vezPlayer) {
            cout << "Escolha o atributo (listado a cima): " << endl;
            cin >> attributeTemp;
            vezPlayer = false;
        }else {
            attributeTemp = (rand() % 4) + 1;
            vezPlayer = true;
        }
        game.SetChoiceAttributes(GetAttribute(attributeTemp));
        game.Turn();
        playerWins = game.GetPlayerWinsTurn();
        cout <<  "Ganhou: " << playerWins.GetNome() << endl;
        cout << "============================" << endl;
    }
}

int main (void) {
    srand(time(NULL));
    setlocale(LC_ALL, "");

    string namefile = "cards.csv";
    ifstream GameIn(namefile, ios::in);

    string model;
    string curbWeight;
    string engineSize;
    string horsePower;
    string price;
    string group;

    int positionList = 1;

    ListCards list;
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

    cout << "BEM VINDO AO SUPERTRUNFO !!" << endl;
    cout << "===========================" << endl;
    Game::GameRules();
    StartGame(list);
    
    return 0;
}
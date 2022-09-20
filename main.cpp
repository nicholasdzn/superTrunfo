#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cctype>
#include "Cards.h"
#include "Player.h"
#include "ListCards.h"

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


int main (void) {
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

     while(!GameIn.eof()){
        getline(GameIn,model,',');
        getline(GameIn,curbWeight,',');
        getline(GameIn,engineSize,',');
        getline(GameIn,horsePower,',');
        getline(GameIn,price,',');
        getline(GameIn,group,'\n');

        list.Insert();
        
    }

    Game game(p1,p2);

    
    
    /*
    Cards card = FactoryCard(
        "ford", 10, 5, 20, 1000, "1A"
    );
    Cards card1 = FactoryCard(
        "fiat", 10, 5, 20, 1200, "3C"
    );

    Player p("Higor");

    p.InsertCardsOnDeck(card);
    p.InsertCardsOnDeck(card1);
    p.RemoveTopCards();
    Cards c = p.CurrentCard();

    cout << c.IsSuperTrunfu() << endl;
    cout << c.model << endl;
    cout << c.curbWeight << endl;
    cout << c.engineSize << endl;
    cout << c.price << endl;
    cout << c.group << endl;
    cout << c.GroupSuperTrunfu() << endl;
    cout << p.GetNome() << endl;
    cout << p.GetValueAttributeOfCurrentCards(AttributeCards::CURB_WEIGHT) << endl;


    while (Game.HasGame()) {
        Game.SetChoiceAttributes();
        Game.Turn();
    }
    */
    return 0;
}
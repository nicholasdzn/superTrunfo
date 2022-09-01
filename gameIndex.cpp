#include <iostream>
#include "gameMechanics.h"
#include <fstream>
#include <iomanip>
#include <string>
#include <string.h>
#include <cctype>
using namespace std;

int main(){
    Game total;
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

        total.Append(model,stoi(curbWeight),stoi(engineSize),stoi(horsePower),stoi(price),group);
    }
}
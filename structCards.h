#include <iostream>
using namespace std;

/*
    Precisamos incluir novas funções para remover erros dos arquivos gameMechanics.cpp e Player.cpp.
    Após isto, irá faltar apenas a correção do arquivo listCards.h e listCards.cpp (nosso embaralhamento) para
    nosso projeto ficar completo 

*/

typedef struct {
    string model;
    int curbWeight;
    int engineSize;
    int horsePower;
    int price;
    string group;
    bool isSuperTrunfo;
} Cards;

enum AttributeCards {
    CURB_WEIGHT,
    ENGINE_SIZE,
    HORSE_POWER,
    PRICE,
};


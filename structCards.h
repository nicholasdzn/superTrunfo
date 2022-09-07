#include <iostream>
using namespace std;

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
    CURB_WEIGHT;
    ENGINE_SIZE;
    HORSE_POWER;
    PRICE;
};


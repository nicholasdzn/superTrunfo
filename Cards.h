#ifndef SCARDS_H
#define SCARDS_H
#include <string>

typedef struct {
    private:
        bool isSuperTrunfo;
        int groupSuperTrunfu;
    public:
        std::string model;
        int curbWeight;
        int engineSize;
        int horsePower;
        int price;
        std::string group;
        bool IsSuperTrunfu () {
            return isSuperTrunfo;
        }
        int GroupSuperTrunfu () {
            return groupSuperTrunfu;
        }
        void SetSuperTrunfu (std::string group) {
            if (group[1] == 'A' && group[0] == '1') {
                isSuperTrunfo = true;
                groupSuperTrunfu = std::stoi(&group[0]);
            } else {
                isSuperTrunfo = false;
                groupSuperTrunfu = -1;
            }
        }
} Cards;

#endif
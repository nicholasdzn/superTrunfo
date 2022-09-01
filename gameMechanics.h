#include <iostream>
using namespace std;


class Game{
    public:
        Game();
        void Append(string m, int c, int e, int h, int p, string g);
        void Serve(int &x);
        bool Full();
        bool Empty();
    private:
        struct Cards{
            string model;
            int curbWeight;
            int engineSize;
            int horsePower;
            int price;
            string group;
            Cards *Next;
        };

        Cards *head;
        Cards *tail;
};
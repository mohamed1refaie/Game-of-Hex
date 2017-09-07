#ifndef HELPERS_H
#define HELPERS_H
#include <iostream>
using namespace std;

class Helpers
{
    public:
        Helpers();
        Helpers(int b[12][12]);
        virtual ~Helpers();
        void print();

    protected:

    private:
        int board[12][12];
};

#endif // HELPERS_H

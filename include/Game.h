#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <bits/stdc++.h>
#include "Helpers.h"
using namespace std;

class Game
{
    public:
        int dx[8]={0,0,1,1,-1,-1};
        int dy[8]={-1,1,-1,0,0,1};                           /// the directions of the movements

        int board[12][12];                                  /// array for the board that we will play on

        vector <pair<int,int> >blue;
        vector< pair<int,int> >red;                         /// two vectors that we will put the nodes that we colored

        map< pair<int,int> , pair<int,int> >before;        /// map to show the before of the current

        Game();
        bool blueleftwin();
        bool bluerightwin();
        bool bluewin();
        bool redupwin();
        bool reddownwin();
        bool redwins();
        bool valid(int i,int j);
        pair<int,int> last(int i,int j);
        void AI(int cpuColor);
        virtual ~Game();

    protected:

    private:
};

#endif // GAME_H

#include <bits/stdc++.h>
#include "Helpers.h"
#include "Game.h"
using namespace std;

int main()
{

    int x,y;               /// the coordinates the player will but
    char c;
    int choice=-1;          /// the color choice for the player
    Game G;
    cout<<"Choose your color"<<endl;
    cout<<"1.BLUE"<<endl;
    cout<<"2.RED"<<endl;
    while(choice!=1&&choice!=2)        /// while loop till the player enter a valid choice
    {
        cin>>choice;
    }
    if(choice==2)                        /// if the player choice is 2 (red) then the cpu will be blue and it must play first so i choose the middle of the board
    {
        G.board[5][5]=1;
        G.blue.push_back(make_pair(5,5));
    }
    while(true)                    /// while loop for the game
    {
        system("cls");/// clear the screen
        Helpers H(G.board);
        H.print();                        /// print the board
        cout<<endl<<endl;
        cout<<"Enter your move : ";              /// asking the user to enter his move
        cin>>x>>y;
        if(G.valid(x,y))           /// if the coordinates enterd is valid so mark the given coordinates by his choice and put it in his vector
        {
            G.board[x][y]=choice;
            if(choice==1)
                G.blue.push_back(make_pair(x,y));
            else
                G.red.push_back(make_pair(x,y));
            if(choice==1)              /// play the cpu move
            G.AI(2);
            else if(choice==2)
            G.AI(1);
        }
        else cout<<"INVALID MOVE "<<endl;          /// if he enterd an invalid coordinates a message appearing to warn him

        if(G.redwins())                     /// if the red wins clear the screen and print the board and notify the player that the red wins and break for the game
        {
            system("cls");
            Helpers H2(G.board);
            H2.print();
            cout<<"RED WINS";
            break;
        }
        else if(G.bluewin())               /// if the blue wins clear the screen and print the board and notify the player that the blue wins and break for the game
        {
            system("cls");
            Helpers H2(G.board);
            H2.print();
            cout<<"BLUE WINS";
            break;
        }

        cout<<"press any key to continue... "<<endl;
        cin.ignore();
        cin.get(c);
    }
    return 0;
}

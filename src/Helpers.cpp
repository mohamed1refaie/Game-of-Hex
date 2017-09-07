#include "Helpers.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

Helpers::Helpers()
{
    memset(board,0,sizeof(board));
}

Helpers::Helpers(int b[12][12])
{
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<12;j++)
            board[i][j]=b[i][j];
    }
}

void Helpers::print()   ///print function that prints the board
{
    for(int i=0;i<=12;i++)
    {
        if(i==0)       ///if i = zero print the numbers from 1 to 11
        {
            for(int j=1;j<=11;j++)
                cout<<j<<" ";
            cout<<endl;
        }
        else if(i==12)  /// else if i = 12 print the numbers from 1 to 11 but prints the padding first
        {
            for(int j=0;j<i;j++)
                cout<<" ";
            for(int j=1;j<=11;j++)
                cout<<j<<" ";
            cout<<endl;
        }
        else          /// else print the padding and print - if the cell is empty and B if the cell equals 1 and R if the cell equals 2
        {
            for(int j=0;j<i-1;j++)
                cout<<" ";
            cout<<i<<" ";         /// print the number of the row first after the padding
            for(int j=1;j<=11;j++)
            {
                if(board[i][j]==0)cout<<"-";
                else if(board[i][j]==1)cout<<"B";
                else if (board[i][j]==2)cout<<"R";
                cout<<" ";
            }
            cout<<i<<endl;   /// print the number of the row after printing the row
        }
    }
}



Helpers::~Helpers()
{
    delete board;
}


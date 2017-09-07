#include "Game.h"
#include <iostream>
#include <bits/stdc++.h>
#include "Helpers.h"
using namespace std;
Game::Game()
{
    memset(board,0,sizeof(board));     /// i memset the board to be all zeros
}

Game::~Game()
{
    delete board;
}


bool Game:: blueleftwin()   /// bfs function to check if we touched the left
{
    bool vis[12][12];    /// visited array for the bfs
    for(int i=0;i<blue.size();i++)   ///check every blue cell that i can touch from it the left or no
    {
        memset(vis,0,sizeof(vis));     /// first i memset the visited array to be zeros
        bool left=false;               /// intialize the bool left by false
        queue< pair<int,int> >bfs;      /// the bfs queue
        bfs.push(blue[i]);               ///push the node
        vis[blue[i].first][blue[i].second]=1;    /// make it visited
        while(!bfs.empty())             /// the break condition
        {
            int x=bfs.front().first;        ///get the x and y for the current node
            int y=bfs.front().second;
            bfs.pop();                       /// pop the node
            if(y==1)left=true;                 /// if i touched the left i make the left = true
            for(int d=0;d<6;d++)               /// check the 6 neighborhood nodes
            {
                int xx=x+dx[d];             /// add the directions to x and y
                int yy=y+dy[d];
                if(xx>=1&&xx<=11&&yy>=1&&yy<=11)      /// first check if there is a valid  neighborhood node
                {
                    if(board[xx][yy]==1&&!vis[xx][yy])       /// and check if the neighborhood node has the blue color
                    {
                        bfs.push(make_pair(xx,yy));        /// if so push it in the bfs queue and make it visited
                        vis[xx][yy]=1;
                    }
                }
            }
        }
        if(left)return true;      /// finially if i touched the left i return true
    }
    return false;             /// else i return false
}

bool Game:: bluerightwin()           /// same as the above but i check if i touch the right
{
    bool vis[12][12];
    bool win=false;
    for(int i=0;i<blue.size();i++)
    {
        memset(vis,0,sizeof(vis));
        bool left=false;
        bool right=false;
        queue< pair<int,int> >bfs;
        bfs.push(blue[i]);
        vis[blue[i].first][blue[i].second]=1;
        while(!bfs.empty())
        {
            int x=bfs.front().first;
            int y=bfs.front().second;
            bfs.pop();
            if(y==11)right=true;
            for(int d=0;d<6;d++)
            {
                int xx=x+dx[d];
                int yy=y+dy[d];
                if(xx>=1&&xx<=11&&yy>=1&&yy<=11)
                {
                    if(board[xx][yy]==1&&!vis[xx][yy])
                    {
                        bfs.push(make_pair(xx,yy));
                        vis[xx][yy]=1;
                    }
                }
            }
        }
        if(right)win=true;
    }
    return win;
}

bool Game:: bluewin()                  /// same as the above but i check if there is a path from the left to the right
{
      bool vis[12][12];
    bool win=false;
    for(int i=0;i<blue.size();i++)
    {
        memset(vis,0,sizeof(vis));
        bool left=false;
        bool right=false;
        queue< pair<int,int> >bfs;
        bfs.push(blue[i]);
        vis[blue[i].first][blue[i].second]=1;
        while(!bfs.empty())
        {
            int x=bfs.front().first;
            int y=bfs.front().second;
            bfs.pop();
            if(y==1)left=true;
            else if(y==11)right=true;
            for(int d=0;d<6;d++)
            {
                int xx=x+dx[d];
                int yy=y+dy[d];
                if(xx>=1&&xx<=11&&yy>=1&&yy<=11)
                {
                    if(board[xx][yy]==1&&!vis[xx][yy])
                    {
                        bfs.push(make_pair(xx,yy));
                        vis[xx][yy]=1;
                    }
                }
            }
        }
        if(right&&left)win=true;
    }
    return win;
}

bool Game::redupwin()             /// same as above but i check if i touch the up
{
    bool vis[12][12];
    for(int i=0;i<red.size();i++)
    {
        memset(vis,0,sizeof(vis));
        bool up=false;
        queue< pair<int,int> >bfs;
        bfs.push(red[i]);
        vis[red[i].first][red[i].second]=1;
        while(!bfs.empty())
        {
            int x=bfs.front().first;
            int y=bfs.front().second;
            bfs.pop();
            if(x==1)up=true;
            for(int d=0;d<6;d++)
            {
                int xx=x+dx[d];
                int yy=y+dy[d];
                if(xx>=1&&xx<=11&&yy>=1&&yy<=11)
                {
                    if(board[xx][yy]==2&&!vis[xx][yy])
                    {
                        bfs.push(make_pair(xx,yy));
                        vis[xx][yy]=1;
                    }
                }
            }
        }
        if(up)return true;
    }
    return false;
}

bool Game:: reddownwin()          /// check if i touch down
{
    bool vis[12][12];
    for(int i=0;i<red.size();i++)
    {
        memset(vis,0,sizeof(vis));
        bool down=false;
        queue< pair<int,int> >bfs;
        bfs.push(red[i]);
        vis[red[i].first][red[i].second]=1;
        while(!bfs.empty())
        {
            int x=bfs.front().first;
            int y=bfs.front().second;
            bfs.pop();
            if(x==11)down=true;
            for(int d=0;d<6;d++)
            {
                int xx=x+dx[d];
                int yy=y+dy[d];
                if(xx>=1&&xx<=11&&yy>=1&&yy<=11)
                {
                    if(board[xx][yy]==2&&!vis[xx][yy])
                    {
                        bfs.push(make_pair(xx,yy));
                        vis[xx][yy]=1;
                    }
                }
            }
        }
        if(down)return true;
    }
    return false;
}

bool Game::redwins()           /// same as above but i check if there is a  red valid path between up and down
{
  bool vis[12][12];
    bool win=false;
    for(int i=0;i<red.size();i++)
    {
        memset(vis,0,sizeof(vis));
        bool up=false;
        bool down=false;
        queue< pair<int,int> >bfs;
        bfs.push(red[i]);
        vis[red[i].first][red[i].second]=1;
        while(!bfs.empty())
        {
            int x=bfs.front().first;
            int y=bfs.front().second;
            bfs.pop();
            if(x==1)up=true;
            else if(x==11)down=true;
            for(int d=0;d<6;d++)
            {
                int xx=x+dx[d];
                int yy=y+dy[d];
                if(xx>=1&&xx<=11&&yy>=1&&yy<=11)
                {
                    if(board[xx][yy]==2&&!vis[xx][yy])
                    {
                        bfs.push(make_pair(xx,yy));
                        vis[xx][yy]=1;
                    }
                }
            }
        }
        if(up&&down)win=true;
    }
    return win;
}

bool Game:: valid(int i,int j)           /// function valid to check if the given i and j are at the board and if the current cell is empty
{
    if(i>=1&&i<=11&&j>=1&&j<=11)
    {
        if(board[i][j]==0)return true;
        else return false;
    }
    else return false;
}

pair<int,int> Game::last(int i,int j)  /// function to get the first empty cell in the path in order to complete the path
{
    int t1,t2;
    pair<int,int>temp;
    while(i!=-1&&j!=-1)
    {
        if(board[i][j]==0)
        {
            t1=i;
            t2=j;
        }
        temp=before[make_pair(i,j)];
        i=temp.first;
        j=temp.second;
    }
    pair<int,int>ret=make_pair(t1,t2);
    return ret;
}


void Game:: AI(int cpuColor)              /// the AI function  given the color that the cpu will play with
{
    if(cpuColor==1)             /// if it is 1 then the cpu plays with blue
    {
        int minimum=10000;             /// i want to get the shortest path from any node to either left or right
        int xnext=-1,ynext=-1;
        bool blueleft=blueleftwin();           /// check if i touch the left
        bool blueright=bluerightwin();          /// check if i touch the right
        bool vis[12][12];                /// visited array
        for(int i=0;i<blue.size();i++)     ///try every node
        {
            memset(vis,0,sizeof(vis));           /// memset the visited array
           int xtemp;
           int ytemp;
           bool emptyy=false;                     /// check the first empty cell
           queue< pair<pair<int,int>,int> >bfs;      /// bfs queue with distance
           bfs.push(make_pair(blue[i],0));          ///push the node with distance 0
           vis[blue[i].first][blue[i].second]=1;      /// make it visited
           before.clear();
           before[blue[i]]=make_pair(-1,-1);
           while(!bfs.empty())
        {
            int x=bfs.front().first.first;            /// get current the coordinates of the node and its distance
            int y=bfs.front().first.second;
            int distance=bfs.front().second;
            bfs.pop();                          /// pop the node

            if(y==1&&distance<minimum&&!blueleft)            /// check if the distance is the shortest to the left and i never touched the left
            {
                minimum=distance;
                pair<int,int>avaliable=last(x,y);
                xnext=avaliable.first;
                ynext=avaliable.second;
            }
            else if(y==11&&distance<minimum&&!blueright)         ///check if the distance is the shortest to the right and i never touched the right
            {
                minimum=distance;
                pair<int,int>avaliable=last(x,y);
                xnext=avaliable.first;
                ynext=avaliable.second;
            }
            for(int d=0;d<6;d++)                      /// try the six neighborhood nodes
            {
                int xx=x+dx[d];
                int yy=y+dy[d];
                if(xx>=1&&xx<=11&&yy>=1&&yy<=11)
                {
                    if((board[xx][yy]==1||board[xx][yy]==0)&&!vis[xx][yy])
                    {
                        bfs.push(make_pair(make_pair(xx,yy),distance+1));
                        vis[xx][yy]=1;
                        before[make_pair(xx,yy)]=make_pair(x,y);  /// update the before of the node that i am going to visitr

                    }
                }
            }
        }
        }
        if(xnext!=-1&&ynext!=-1)         /// check if i found a valid empty cell in the way to the shortest path i mark it
        {
            board[xnext][ynext]=1;
            blue.push_back(make_pair(xnext,ynext));
        }
    }
    else               /// same as above but in the red case
    {
        if(red.size()==0)                  /// as the first move i try to put red in the middle
        {
            if(board[5][5]!=0)
            {
                board[5][4]=2;
                red.push_back(make_pair(5,4));
            }
            else {
                board[5][5]=2;
                red.push_back(make_pair(5,5));
            }
            return;
        }
        int minimum=10000;
        int xnext=-1,ynext=-1;
        bool redup=redupwin();
        bool reddown=reddownwin();
        bool vis[12][12];
        for(int i=0;i<red.size();i++)
        {
            memset(vis,0,sizeof(vis));
           int xtemp;
           int ytemp;
           bool emptyy=false;
           queue< pair<pair<int,int>,int> >bfs;
           bfs.push(make_pair(red[i],0));
           vis[red[i].first][red[i].second]=1;
           before.clear();
           before[red[i]]=make_pair(-1,-1);
           while(!bfs.empty())
        {
            int x=bfs.front().first.first;
            int y=bfs.front().first.second;
            int distance=bfs.front().second;
            bfs.pop();
            if(x==1&&distance<minimum&&!redup)
            {
                minimum=distance;
                pair<int,int>avaliable=last(x,y);
                xnext=avaliable.first;
                ynext=avaliable.second;
            }
            else if(x==11&&distance<minimum&&!reddown)
            {
                minimum=distance;
                pair<int,int>avaliable=last(x,y);
                xnext=avaliable.first;
                ynext=avaliable.second;
            }
            for(int d=5;d>=0;d--)
            {
                int xx=x+dx[d];
                int yy=y+dy[d];
                if(xx>=1&&xx<=11&&yy>=1&&yy<=11)
                {
                    if((board[xx][yy]==2||board[xx][yy]==0)&&!vis[xx][yy])
                    {
                        bfs.push(make_pair(make_pair(xx,yy),distance+1));
                        vis[xx][yy]=1;
                        before[make_pair(xx,yy)]=make_pair(x,y);

                    }
                }
            }
        }
        }
        if(xnext!=-1&&ynext!=-1)
        {
            board[xnext][ynext]=2;
            red.push_back(make_pair(xnext,ynext));
        }
    }
}


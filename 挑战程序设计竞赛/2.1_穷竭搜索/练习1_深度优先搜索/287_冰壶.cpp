#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;

typedef pair<int, int> P;

P start, _end;
int w, h;
vector<vector<int> > G;
int asw = 15;

int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};

bool isValid(int x, int y){
    if(x >= 0 && x < h && y >= 0 && y < w)  return true;
    return false;
}

void DFS_Traversal(P cur, int direction, int num){
    if(num > 10)    return ;
    if(cur == _end){
        if(num < asw && num < 11)   asw = num;
        return ;
    }
    int x = cur.first, y = cur.second;
    int newX = x + X[direction];
    int newY = y + Y[direction];
    if(isValid(newX, newY) == false)    return ;
    if(G[newX][newY] == 0 || G[newX][newY] == 2)  DFS_Traversal(P(newX, newY), direction, num);
    else if(G[newX][newY] == 1){
        G[newX][newY] = 0;
        for(int i = 0; i < 4; i++){
            //if((direction + 2) % 4 == i)    continue;
            int tempX = x + X[i];
            int tempY = y + Y[i];
            if(isValid(tempX, tempY) == false)    continue;
            if(G[tempX][tempY] == 0 || G[tempX][tempY] == 2)  DFS_Traversal(P(tempX, tempY), i, num + 1);
            else if(G[tempX][tempY] == 1)     continue;
            else{
                if(num + 1 < asw && num + 1 < 11)   asw = num + 1;
            }
            //DFS_Traversal(P(tempX, tempY), i, num + 1);
        }
        G[newX][newY] = 1;
    }
    else{
        if(num < asw && num < 11)   asw = num;
    }
    return ;
}

void DFS(P cur){
    for(int i = 0; i < 4; i++){
        int newX = cur.first + X[i];
        int newY = cur.second + Y[i];
        if(isValid(newX, newY) == false)    continue;
        if(G[newX][newY] == 0)  DFS_Traversal(cur, i, 1);
        else if(G[newX][newY] == 1)     continue;
        else    asw = 1;
    }
    return ;
}

int main()
{
    while(scanf("%d %d", &w, &h) != EOF){
        if(w == 0 && h == 0)    break;
        G.resize(h, vector<int>(w));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                scanf("%d", &G[i][j]);
                if(G[i][j] == 2){
                    start = P(i, j);
                }
                else if(G[i][j] == 3){
                    _end = P(i, j);
                }
            }
        }
        DFS(start);
        //cout<<"------"<<endl;
        if(asw == 15)   printf("-1\n");
        else    printf("%d\n", asw);
        //cout<<"------"<<endl;
        G.clear();
        asw = 15;
    }
    

    return 0;
}

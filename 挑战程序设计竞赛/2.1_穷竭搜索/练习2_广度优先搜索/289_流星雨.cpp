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

const int MAXN = 300 + 10;
const int INF = 0x3f3f3f3f;

int _X[4] = {-1, 0, 1, 0};
int _Y[4] = {0, -1, 0, 1};

int M;
vector<vector<int> > G(MAXN, vector<int>(MAXN, INF));
vector<vector<bool> > visited(MAXN, vector<bool>(MAXN, false));

struct stu{
    int x, y, t;
};

int asw = INF;

bool isValid(int x, int y){
    if(x >= 0 && x <= 301 && y >= 0 && y <= 301 && visited[x][y] == false)    return true;
    return false;
}

void BFS(){
    stu s;
    s.x = 0;    s.y = 0;    s.t = 0;
    queue<stu> que;
    que.push(s);
    while(!que.empty()){
        int size = que.size();
        for(int k = 0; k < size; k++){
            stu temp = que.front();     que.pop();
            int row = temp.x, col = temp.y, t = temp.t;
            visited[row][col] = true;
            if(G[row][col] == INF){
                asw = t;
                return ;
            }
            //if(G[row][col] > t)     que.push(stu{row, col, t + 1});
            for(int i = 0; i < 4; i++){
                int newX = row + _X[i];
                int newY = col + _Y[i];
                if(isValid(newX, newY) && G[newX][newY] > t + 1)    que.push(stu{newX, newY, t + 1});
            }
        }
    }
    return ;
}

int main()
{
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int X, Y, T;    scanf("%d %d %d", &X, &Y, &T);
        G[X][Y] = min(G[X][Y], T);
        for(int j = 0; j < 4; j++){
            int newX = X + _X[j];
            int newY = Y + _Y[j];
            if(isValid(newX, newY))     G[newX][newY] = min(G[newX][newY], T);
        }
    }
    BFS();
    if(asw == INF)  printf("-1\n");
    else    printf("%d\n", asw);

    return 0;
}

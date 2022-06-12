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

int asw = 0;
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};

void DFS(vector<vector<char> > &graph,vector<vector<bool> > &visited, int cur_row, int cur_col){
    asw++;
    visited[cur_row][cur_col] = true;
    for(int i = 0; i < 4; i++){
        int newX = cur_row + X[i];
        int newY = cur_col + Y[i];
        if(newX >= 0 && newX < graph.size() && newY >= 0 && newY < graph[0].size()
        && visited[newX][newY] == false && graph[newX][newY] == '.'){
            DFS(graph, visited, newX, newY);
        }
    }
    return ;
}

int main()
{
    int W, H;
    while(cin>>W>>H){
        if(W == 0 && H == 0)    break;
        asw = 0;
        vector<vector<char> > graph(H, vector<char>(W));
        vector<vector<bool> > visited(H, vector<bool>(W, false));
        int s_row = 0, s_col = 0;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cin>>graph[i][j];
                if(graph[i][j] == '@'){
                    s_row = i;
                    s_col = j;
                }
            }
        }
        DFS(graph, visited, s_row, s_col);
        cout<<asw<<endl;
    }
    
    return 0;
}

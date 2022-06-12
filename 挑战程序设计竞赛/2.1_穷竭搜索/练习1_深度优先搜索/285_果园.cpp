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

void dfs(vector<vector<char> > &graph, vector<vector<bool> > &visited, int cur_row, int cur_col, char cur_fruit){
    visited[cur_row][cur_col] = true;
    for(int i = 0; i < 4; i++){
        int newX = cur_row + X[i];
        int newY = cur_col + Y[i];
        if(newX >= 0 && newX < graph.size() && newY >= 0 && newY < graph[0].size()
        && visited[newX][newY] == false && graph[newX][newY] == cur_fruit){
            dfs(graph, visited, newX, newY, cur_fruit);
        }
    }
    return ;
}

void DFS(vector<vector<char> > &graph, vector<vector<bool> > &visited){
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            if(visited[i][j] == false){
                asw++;
                dfs(graph, visited, i, j, graph[i][j]);
            }
        }
    }
    return ;
}

int main()
{
    int H, W;
    while(cin>>H>>W){
        if(H == 0 && W == 0)    break;
        asw = 0;
        vector<vector<char> > graph(H, vector<char>(W));
        vector<vector<bool> > visited(H, vector<bool>(W, false));
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cin>>graph[i][j];
            }
        }
        DFS(graph, visited);
        cout<<asw<<endl;
    }
    

    return 0;
}

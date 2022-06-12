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

int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};

int asw = 0;

void BFS(vector<vector<char> > &graph, int &s_row, int &s_col, char cur){
    vector<vector<bool> > visited(graph.size(), vector<bool>(graph[0].size(), false));
    queue<pair<int, int> > que;
    pair<int, int> root;
    root.first = s_row;
    root.second = s_col;
    que.push(root);
    visited[root.first][root.second] = true;
    while(!que.empty()){
        int size = que.size();
        for(int j = 0; j < size; j++){
            pair<int, int> temp = que.front();
            que.pop();
            if(graph[temp.first][temp.second] == cur){
                s_row = temp.first;
                s_col = temp.second;
                return ;
            }
            for(int k = 0; k < 4; k++){
                int newX = temp.first + X[k];
                int newY = temp.second + Y[k];
                pair<int, int> new_temp = make_pair(newX, newY);
                if(newX >= 0 && newX < graph.size() && newY >= 0 && newY < graph[0].size()
                && visited[newX][newY] == false && graph[newX][newY] != 'X'){
                    que.push(new_temp);
                    visited[newX][newY] = true;
                }
            }
        }
        asw++;
    }
    return ;
}

int main()
{
    int H, W, N;    cin>>H>>W>>N;
    int s_row = 0, s_col = 0;
    vector<vector<char> > graph(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin>>graph[i][j];
            if(graph[i][j] == 'S'){
                s_row = i;
                s_col = j;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        BFS(graph, s_row, s_col, char(i + '0'));
    }

    cout<<asw<<endl;

    return 0;
}

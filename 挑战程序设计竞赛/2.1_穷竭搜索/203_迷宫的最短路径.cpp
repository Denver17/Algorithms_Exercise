#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int X[4] = {-1, 0, 0, 1};
int Y[4] = {0, -1, 1, 0};

vector<vector<char> > graph;
vector<vector<bool> > visited;
queue<pair<int, int> > que;
int asw = 0;

void BFS(int s_row, int s_col){
    pair<int, int> start(s_row, s_col);
    que.push(start);
    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; i++){
            pair<int, int> temp = que.front();
            que.pop();
            int cur_row = temp.first;
            int cur_col = temp.second;
            //需要剪枝操作，不然有重复位置进入队列造成内存超限
            //visited[cur_row][cur_col] = true;
            for(int i = 0; i < 4; i++){
                int newRow = cur_row + X[i];
                int newCol = cur_col + Y[i];
                if(newRow < 0 || newRow >= graph.size() || newCol < 0 || newCol >= graph[0].size() || visited[newRow][newCol] == true) continue;
                if(graph[newRow][newCol] == '.'){
                    pair<int, int> new_temp;
                    new_temp.first = newRow;
                    new_temp.second = newCol;
                    que.push(new_temp);
                    visited[newRow][newCol] = true;
                }
                else if(graph[newRow][newCol] == 'G'){
                    asw++;
                    return ;
                }
            }
        }
        asw++;
    }
    return ;
}


int main()
{
    int N, M;
    cin>>N>>M;
    int s_row = 0, s_col = 0;
    graph.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>graph[i][j];
            if(graph[i][j] == 'S'){
                s_row = i;  s_col = j;
            }
        }
    }

    BFS(s_row, s_col);

    cout<<asw<<endl;

    return 0;
}
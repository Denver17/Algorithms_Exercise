#include<iostream>
#include<vector>
using namespace std;

int asw = 0;
vector<vector<bool> > visited;

int X[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int Y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void DFS(vector<vector<char> > &graph, int row, int col){
    if(graph[row][col] == '.'){
        visited[row][col] = true;
        return ;
    }
    visited[row][col] = true;
    for(int i = 0; i < 8; i++){
        int newRow = row + X[i];
        int newCol = col + Y[i];
        if(newRow >=0 && newRow < graph.size() && newCol >= 0 && newCol < graph[0].size()
        && graph[newRow][newCol] == 'W' && visited[newRow][newCol] == false){
            DFS(graph, newRow, newCol);
        }
    }
    return ;
}

void dfs(vector<vector<char> > &graph){
    int row = graph.size(), col = graph[0].size();
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(visited[i][j] == false){
                DFS(graph, i, j);
                if(graph[i][j] == 'W')  asw++;
            }
        }
    }
    return ;
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<vector<char> > graph(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>graph[i][j];
        }
    }
    dfs(graph);
    cout<<asw<<endl;
    return 0;
}
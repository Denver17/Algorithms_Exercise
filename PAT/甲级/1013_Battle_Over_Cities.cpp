#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

const int MAXN = 1000 + 10;

vector<bool> visited;
vector<int> Node[MAXN];

void dfs(int start){
    visited[start] = true;
    for(int i = 0; i < Node[start].size(); i++){
        if(visited[Node[start][i]] == false){
            dfs(Node[start][i]);
        }
    }
    return ;
}

int query(int size){
    int asw = 0;
    for(int i = 1; i < size; i++){
        if(visited[i] == false){
            dfs(i);
            asw++;
        }
    }
    return asw - 1;
}

int main()
{
    int N, M, K;    scanf("%d %d %d", &N, &M, &K);
    
    for(int i = 0; i < M; i++){
        int v1, v2; scanf("%d %d", &v1, &v2);
        Node[v1].push_back(v2);
        Node[v2].push_back(v1);
    }
    for(int i = 0; i < K; i++){
        visited.clear();
        visited.resize(N + 1, false);
        int temp;   scanf("%d", &temp);
        visited[temp] = true;
        int asw = query(N + 1);
        printf("%d\n", asw);
    }

    return 0;
}


#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MAXV = 10001;

vector<int> Adj[MAXV];
bool visited[MAXV] = {false};
vector<int> asw;
int num = 0;        //访问DFS次数，即连通分量个数

void DFS(int u,int depth){
    visited[u] = true;
    asw[u] = depth;
    for(int i = 0; i < Adj[u].size(); i++){
        int v = Adj[u][i];
        if(visited[v] == false){
            DFS(v,depth+1);
        }
    }
}

void DFSTraversal(int N,int start){
    for(int i = start; i <= N; i++){
        if(visited[i] == false){
            num++;
            DFS(i,1);
        }
    }
    return ;
}


int main()
{
    int N;
    scanf("%d",&N);
    for(int i = 0; i < N-1; i++){
        int node1,node2;
        scanf("%d%d",&node1,&node2);
        Adj[node1].push_back(node2);
        Adj[node2].push_back(node1);
    }
    asw.resize(N+1);

    int dmax = 0;
    vector<int> dep(N+1);
    for(int i = 1; i <= N; i++){
        DFSTraversal(N,i);
        if(num != 1)    { printf("Error: %d components",num); return 0;}
        else{
            for(int j = 1; j < asw.size(); j++){
                if(asw[j] > dmax)   dmax = asw[j];
            }
            dep[i] = dmax;
            fill(asw.begin(),asw.end(),0);
            dmax = 0;
            num = 0;
            for(int j = 0; j < MAXV; j++)   visited[j] = false;
        }
    }
    dmax = 0;
    for(int i = 0; i <= N; i++){
        if(dep[i] > dmax)   dmax = dep[i];
    }
    for(int i = 1; i <= N; i++){
        if(dep[i] == dmax)  printf("%d\n",i);
    }
    return 0;
}

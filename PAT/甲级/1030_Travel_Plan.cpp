#include<iostream>
#include<cstdio>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

const int MAXV = 510;
const int INF = INT_MAX/2;

vector<vector<int>> G(MAXV,vector<int>(MAXV,INF));
vector<vector<int>> G_cost(MAXV,vector<int>(MAXV,INF));
vector<int> d(MAXV);
//vector<int> c(MAXV);
vector<bool> visited(MAXV,false);
vector<int> pre[MAXV];          //存储某一结点的前驱结点(单源最短路上的)
vector<int> path,tempPath;      //存储最优路径与临时路径
int cost = INF;

void Dijkstra(int start,int num){
    fill(d.begin(),d.end(),INF);
    //fill(c.begin(),c.end(),INF);
    d[start] = 0;
    //c[start] = 0;
    for(int i = 0; i < num; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < num; j++){
            if(visited[j] == false && d[j] < MIN){      //在未访问结点中寻找d[]最小的结点
                MIN = d[j];
                u = j;
            }
        }

        if( u == -1 )   return ;
        visited[u] = true;

        for(int v = 0; v < num; v++){
            if(G[u][v] != INF && visited[v] == false){
                if(d[v] > d[u] + G[u][v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[v] == d[u] + G[u][v]){
                    pre[v].push_back(u);
                }
            }
        }    

    }
    return ;
}

void DFS(int start,int cur){
    if(start == cur){
        tempPath.push_back(cur);
        int value = 0;
        for(int i = tempPath.size()-1; i > 0; i--){
            int id = tempPath[i], id_next = tempPath[i-1];
            value += G_cost[tempPath[i]][tempPath[i-1]];
        }
        if(value < cost){
            cost = value;
            path = tempPath;
        }
        tempPath.pop_back();
        return ;
    }
    tempPath.push_back(cur);
    for(int i = 0; i < pre[cur].size(); i++){
        DFS(start,pre[cur][i]);
    }
    tempPath.pop_back();
}

int main()
{
    int N,M,S,D;
    cin>>N>>M>>S>>D;
    for(int i = 0; i < M; i++){
        int c1,c2,distance,cost;
        cin>>c1>>c2>>distance>>cost;
        G[c1][c2] = distance;
        G_cost[c1][c2] = cost;
        G[c2][c1] = distance;
        G_cost[c2][c1] = cost;
    }

    Dijkstra(S,N);

    DFS(S,D);

    for(int i = path.size() - 1; i >= 0; i--)    printf("%d ",path[i]);
    printf("%d %d",d[D],cost);

    return 0;
}


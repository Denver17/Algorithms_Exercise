#include<iostream>
#include<cstdio>
#include<vector>
#include<limits.h>
using namespace std;

//1、不要轻易直接开辟vector空间，否则pushback时可能出问题
//2、本题有三个优先级需要判定
//3、无向图艹了

const int MAXV = 510;
const int INF = INT_MAX/2;

vector<vector<int>> G(MAXV,vector<int>(MAXV,INF));
vector<int> d(MAXV);        
vector<int> point_weight(MAXV);
vector<bool> visited(MAXV,false);
vector<int> pre[MAXV];              //记录当前结点的前驱结点(在单源最短路上的)
vector<int> path(MAXV);             //最终的最优路径
vector<int> temppath;         //暂时存储的路径

int send = -INF;       //所有最短路径中最少送出自行车的数目
int take_back = INF;  //所有路径中最少取回的自行车数目


void Dijkstra(int start,int N){
    fill(d.begin(),d.end(),INF);
    d[start] = 0;
    for(int i = 0; i < N; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < N; j++){
            if(visited[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        if( u == -1 )   return ;
        visited[u] = true;

        for(int v = 0; v < N; v++){
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

void DFS(int start,int cur,int N,int standard){
    if(start == cur){
        temppath.push_back(cur);
        
        int s_value = 0;
        int t_value = 0;
        for(int i = temppath.size() - 2; i >= 0; i--){
            if( point_weight[temppath[i]] - standard > 0 ){
                t_value += point_weight[temppath[i]] - standard;
            }
            else if(point_weight[temppath[i]] - standard <= 0){ 
                if(t_value >= abs(point_weight[temppath[i]] - standard) ){
                    t_value += point_weight[temppath[i]] - standard;
                }
                else{
                    s_value += t_value + (point_weight[temppath[i]] - standard);
                    t_value = 0;
                }
            }
        }
        if( s_value > send ){
            send = s_value;
            path = temppath;
            take_back = t_value;
        }
        else if(s_value == send && t_value < take_back){
            take_back = t_value;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }

    temppath.push_back(cur);
    for(int i = 0; i < pre[cur].size(); i++){
        DFS(start,pre[cur][i],N,standard);
    }
    temppath.pop_back();
}

int main()
{
    int C,N,S,M;        //C是最大容量，N是结点个数，S是问题结点编号，M是边的个数
    cin>>C>>N>>S>>M;
    point_weight[0] = 0;
    for(int i = 1; i <= N; i++){
        cin>>point_weight[i];
    }
    for(int i = 0; i  < M; i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        G[from][to] = weight;
        G[to][from] = weight;
    }

    Dijkstra(0,N+1);

    DFS(0,S,N+1,C/2);

    printf("%d %d",abs(send),path[path.size()-1]);
    for(int i = path.size() - 2; i >= 0; i--){
        printf("->%d",path[i]);
    }
    printf(" %d",take_back);

    return 0;
}

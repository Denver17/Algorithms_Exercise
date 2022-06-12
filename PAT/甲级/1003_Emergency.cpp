#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;
vector<vector<int>> G(MAXV,vector<int>(MAXV,INF));
vector<int> d(MAXV);                    
vector<int> teams_num(MAXV,0);            //点权，即城市中救援队的数量
vector<int> w(MAXV,0);                      //最终的最大物资
vector<int> nums(MAXV,0);                  //最短路径条数
vector<bool> visited(MAXV,false);

void Dijkstra(int start,int end,int N){
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
            if( u == -1)    return ;
            visited[u] = true;
            for(int v = 0; v < N; v++){
                if(visited[v] == false && G[u][v] != INF){
                    if(d[u] + G[u][v] < d[v]){
                        d[v] = d[u] + G[u][v];
                        nums[v] = nums[u];
                        w[v] = w[u] + teams_num[v];
                    }
                    else if(d[u] + G[u][v] == d[v]){
                        nums[v] += nums[u];
                        if(w[u] + teams_num[v] > w[v]){
                            w[v] = w[u] + teams_num[v];
                        }
                    }
                }
            }
    }
    return ;
}

int main()
{
    int N,M,C1,C2;
    scanf("%d%d%d%d",&N,&M,&C1,&C2);
    for(int i = 0; i < N; i++){
        scanf("%d",&teams_num[i]);
    }
    for(int i = 0; i < M; i++){
        int c1,c2,L;
        scanf("%d%d%d",&c1,&c2,&L);
        G[c1][c2] = L;
        G[c2][c1] = L;
    }
    

    //初始化路径数目
    nums[C1] = 1;               //初始结点是一定至少有一条路径的
    w[C1] = teams_num[C1];

    Dijkstra(C1,C2,N);

    printf("%d %d",nums[C2],w[C2]);

    return 0;
}

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int MAXV = 1001;
int asw = 0;


void query(vector<vector<int>> &G,vector<bool> &visited,int num,int L){
    queue<int> que;
    que.push(num);
    visited[num] = true;
    int layer = 0;
    while( !que.empty() ){
        int size = que.size();
        layer++;
        for(int i = 0; i < size; i++){
            int u = que.front();
            que.pop();
            for(int j = 0; j < G.size(); j++){
                if(visited[j] == false && G[j][u] == 1){
                    que.push(j);
                    visited[j] = true;
                    asw++;
                }
            }
        }
        if(layer == L)  return ;
    }
    
    // visited[num] = true;
    // asw++;
    // if(L == 0)  return ;
    // for(int j = 0; j < G.size(); j++){
    //     if(G[j][num] == 1 && visited[j] == false)      //若j关注了num，那么j就会转发
    //         query(G,visited,j,L-1);
    // }
    return ;
}

int main()
{
    int N,L;
    scanf("%d%d",&N,&L);
    vector<vector<int>> G(N,vector<int>(N,0));
    vector<bool> visited(N,false);
    for(int i = 0; i < N; i++){
        int M;          //这个结点指向的结点个数
        scanf("%d",&M);
        for(int j = 0; j < M; j++){
            int num;
            scanf("%d",&num);
            G[i][num-1] = 1;
        }
    }

    int K;      //查询对象的个数
    scanf("%d",&K);
    for(int i = 0; i < K; i++){
        int num;
        scanf("%d",&num);
        query(G,visited,num-1,L);
        printf("%d\n",asw);
        asw = 0;
        fill(visited.begin(),visited.end(),false);
    }


    return 0;
}

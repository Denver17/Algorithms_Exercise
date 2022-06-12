//暴力计算不可行，动态规划，记录每一个结点到第一个结点的距离，再计算

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int sum = 0;

void shortest_distance(vector<int> &dis,int exit1,int exit2){
    int size = dis.size();
    int left = min(exit1,exit2);
    int right = max(exit1,exit2);
    int asw1 = 0, asw2 = 0;
    asw1 = dis[right] - dis[left];
    asw2 = sum - asw1;
   
    int asw = min(asw1,asw2);
    printf("%d\n",asw);
    return ;
}

int main()
{
    int N;
    cin>>N;
    vector<int> vec(N+1);
    for(int i = 1; i <= N; i++){
        scanf("%d",&vec[i]);
    }
    vector<int> dis(N+1);
    dis[0] = 0;
    dis[1] = 0;
    for(int i = 2; i <= N; i++){
        dis[i] = dis[i-1] + vec[i-1]; 
    }
    for(int i = 1; i <= N; i++){
        sum += vec[i];
    }
    int M;
    scanf("%d",&M);
    for(int i = 0; i < M; i++){
        int exit1,exit2;
        scanf("%d%d",&exit1,&exit2);
        shortest_distance(dis,exit1,exit2);
    }

    return 0;
}


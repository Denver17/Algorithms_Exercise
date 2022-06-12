#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<cmath>
using namespace std;

const int MAXN = 1e3 + 20;
const int INF = 1e8;

struct node{
    int v;
    int dis;
};

struct station{
    double average;
    int index;
    int dmin;
};

vector<station> asw;
vector<node> adj[MAXN];
int d[MAXN];
vector<bool> visited(MAXN, false);
vector<int> pre[MAXN];

bool cmp(station a, station b){
    if(a.dmin != b.dmin)    return a.dmin > b.dmin;
    else if(a.average != b.average)  return a.average < b.average;
    else    return a.index < b.index;
}

void Dijkstra(int s, int N, int M, int D){
    fill(d, d + MAXN, INF);
    d[s] = 0;
    
    for(int i = 1; i <= N + M; i++){
        int u = -1, MIN = INF;
        for(int j = 1; j <= N + M; j++){
            if(visited[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        
        if(u == -1) continue;      

        visited[u] = true;
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].v;
            if(visited[v] == false && d[u] + adj[u][j].dis < d[v]){
                d[v] = d[u] + adj[u][j].dis;
            }
        }
    }
    

    int sum = 0, _min = INF;
    for(int i = 1; i <= N; i++){
        if(visited[i] == true && d[i] > D)    return ;
        else if(visited[i] == true && d[i] <= D){
            sum += d[i];
        }
        if(d[i] < _min){
            _min = d[i];
        }
    }

    station temp;
    temp.index = s - N;
    //temp.average = (double)sum / N;
    //temp.average = round( (double)sum * 10 / N) / 10;
    temp.average = ( (double)sum * 10 / N) / 10;
    temp.dmin = _min;
    asw.push_back(temp);

    return ;
}


int main()
{
    int N, M, K, D;     scanf("%d %d %d %d", &N, &M, &K, &D);
    for(int i = 0; i < K; i++){
        string P1, P2;  
        int Dist;   
        //scanf("%s %s %d", &P1, &P2, &Dist);
        cin>>P1>>P2>>Dist;
        node v1, v2;
        int num1, num2;
        if(P1[0] == 'G'){
            P1.erase(0, 1);
            num1 = atoi(P1.c_str()) + N;
        }
        else{
            num1 = atoi(P1.c_str());
        }
        if(P2[0] == 'G'){
            P2.erase(0, 1);
            num2 = atoi(P2.c_str()) + N;
        }
        else{
            num2 = atoi(P2.c_str());
        }
        v1.v = num1;    v1.dis = Dist;
        v2.v = num2;    v2.dis = Dist;
        adj[num1].push_back(v2);
        adj[num2].push_back(v1);
    }
    
    for(int i = 1; i <= M; i++){
        visited.clear();
        visited.resize(MAXN, false);
        int s = N + i;
        Dijkstra(s, N, M, D);
    }

    sort(asw.begin(), asw.end(), cmp);

    if(asw.size() == 0){
        printf("No Solution\n");
        return 0;
    }
    else{
        printf("G%d\n", asw[0].index);
        printf("%.1f %.1f\n", (double)asw[0].dmin, asw[0].average);
    }

    return 0;
}


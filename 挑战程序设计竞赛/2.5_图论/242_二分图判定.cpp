#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int MAXN = 1000 + 10;
vector<int> G[MAXN];
vector<bool> visited(MAXN, false);
vector<bool> color(MAXN);

bool BFS(int cur){
    queue<int> que;
    que.push(cur);
    visited[cur] = true;
    color[cur] = true;
    while(!que.empty()){
        int node = que.front();
        que.pop();
        for(int i = 0; i < G[node].size(); i++){
            if(visited[G[node][i]] == false){
                visited[G[node][i]] = true;
                color[G[node][i]] = !color[node];
                que.push(G[node][i]);
            }
            else{
                if(color[G[node][i]] == color[node])    return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;  cin>>n;
    int x, y;
    while(cin>>x>>y){
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            if(BFS(i) == false){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}

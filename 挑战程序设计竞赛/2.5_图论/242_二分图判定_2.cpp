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
vector<int> color(MAXN, 0);

bool DFS(int cur, int c){
    visited[cur] = true;
    color[cur] = c;
    for(int i = 0; i < G[cur].size(); i++){
        if(color[G[cur][i]] == c)   return false;
        if(visited[G[cur][i]] == false && !DFS(G[cur][i], -c))  return false;
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
        if(visited[i] == true)  continue;
        //对某个结点染色为1
        if(!DFS(i, 1)){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;

    return 0;
}

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

const int MAXN = 15;
const int INF = 0x3f3f3f3f;
int n;

vector<vector<int> > dp(1 << MAXN, vector<int>(MAXN, INF));
vector<vector<int> > graph(MAXN, vector<int>(MAXN, 0));

void solve(){
    //dp[S][v]表示已经访问过的顶点集合为S,当前顶点为v,从v出发访问剩余所有顶点
    //最终回到起点的路径的权重之和的最小值
    dp[(1 << n) - 1][0] = 0;

    for(int S = (1 << n) - 2; S >= 0; S--){
        for(int v = 0; v < n; v++){
            for(int u = 0; u < n; u++){
                if(!(S >> u & 1) && graph[v][u] != -1){
                    dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + graph[v][u]);
                }
            }
        }
    }

    cout<<dp[0][0]<<endl;
    return ;
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int val;    cin>>val;
            graph[i][j] = val;
        }
    }
    solve();

    return 0;
}
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


int main()
{
    int n, K;   cin>>n>>K;
    vector<int> a(n);
    vector<int> m(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        cin>>m[i];
    }
    vector<vector<int> > dp(n + 1, vector<int>(K + 1, -1));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= K; j++){
            if(dp[i][j] >= 0)   dp[i + 1][j] = m[i];
            else if(j < a[i] || dp[i + 1][j - a[i]] <= 0)   dp[i + 1][j] = -1;
            else    dp[i + 1][j] = dp[i + 1][j - a[i]] - 1;
        }
    }
    if(dp[n][K] >= 0)    cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;

    return 0;
}

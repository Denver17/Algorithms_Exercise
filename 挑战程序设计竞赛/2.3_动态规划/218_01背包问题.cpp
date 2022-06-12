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
    int n, W;   cin>>n>>W;
    vector<int> weight(n);
    vector<int> values(n);
    vector<vector<int> > dp(n, vector<int>(W + 1, 0));
    for(int i = 0; i < n; i++){
        cin>>weight[i]>>values[i];
    }
    for(int i = 0; i < W + 1; i++){
        if(i >= weight[0])    dp[0][i] = values[0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < W + 1; j++){
            if(j < weight[i])   dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + values[i]);
        }
    }

    cout<<dp[n - 1][W]<<endl;

    return 0;
}

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

const int INF = 1e9 + 1;

int main()
{
    int n, W;   cin>>n>>W;
    vector<int> weight(n + 1);
    vector<int> values(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>weight[i]>>values[i];
    }
    int max_value = 1e4 + 1;
    vector<vector<int> > dp(100 + 1, vector<int>(max_value, INF));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < max_value; j++){
            //此处。。。。。
            dp[i][j] = dp[i - 1][j];
            if(j >= values[i]){
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - values[i]] + weight[i]);
            }
        }
    }
    
    int asw = 0;
    for(int i = 0; i < max_value; i++){
        if(dp[n][i] <= W)   asw = i;
    }

    cout<<asw<<endl;

    return 0;
}

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
    int n, m, M;    cin>>n>>m>>M;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)  cin>>vec[i];
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 0; i < n + 1; i++)  dp[i][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m + 1;j++){
            if(j - 1 - vec[i] >= 0)
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - vec[i]] + M) % M;
            else
                dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
        }
    }

    cout<<dp[n][m]<<endl;

    return 0;
}

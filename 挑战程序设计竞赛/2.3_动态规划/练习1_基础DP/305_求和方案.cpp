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

const int mod = 1000000000;

int main()
{
    int N;  cin>>N;
    vector<int> dp(N + 1);
    dp[1] = 1;
    for(int i = 2; i <= N; i++){
        if(i % 2 == 1)  dp[i] = dp[i - 1];
        else    dp[i] = (dp[i - 1] + dp[i / 2]) % mod;
    }

    cout<<dp[N]<<endl;

    return 0;
}
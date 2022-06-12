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
    int n, M;
    while(cin>>n>>M){
        if(n == 0 && M == 0)    break;
        vector<int> A(n), C(n);
        for(int i = 0; i < n; i++)  cin>>A[i];
        for(int i = 0; i < n; i++)  cin>>C[i];
        //dp[i][j]表示用前i种硬币凑成金额j时第i种硬币最多还剩多少个,-1表示凑不成
        vector<vector<int> > dp(n + 1, vector<int>(M + 1, -1));
        dp[0][0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= M; j++){
                if(dp[i][j] >= 0)   dp[i + 1][j] = C[i];
                else if(j < A[i] || dp[i + 1][j - A[i]] <= 0)   dp[i + 1][j] = -1;
                else    dp[i + 1][j] = dp[i + 1][j - A[i]] - 1;
            }
        }
        int asw = 0;
        for(int i = 1; i <= M; i++){
            if(dp[n][i] >= 0)    asw++;
        }
        cout<<asw<<endl;
    }
    

    return 0;
}
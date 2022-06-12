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
    int m, n;   cin>>m>>n;
    string s, t;
    cin>>s;
    cin>>t;
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout<<dp[m][n]<<endl;

    return 0;
}

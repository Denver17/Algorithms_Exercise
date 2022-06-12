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
    int r;      cin>>r;
    vector<vector<int> > vec;
    for(int i = 0; i < r; i++){
        vector<int> temp(i + 1);
        for(int j = 0; j < i + 1; j++){
            cin>>temp[j];
        }
        vec.push_back(temp);
    }
    
    vector<vector<int> > dp(r, vector<int>(r, 0));
    dp[0][0] = vec[0][0];
    for(int i = 1; i < r; i++){
        for(int j = 0; j < i + 1; j++){
            if(j == 0)  dp[i][j] = dp[i - 1][0] + vec[i][j];
            else if(j == i) dp[i][j] = dp[i - 1][j - 1] + vec[i][j];
            else    dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + vec[i][j];
        }
    }

    int asw = 0;
    for(int i = 0; i < r; i++){
        if(dp[r - 1][i] > asw)  asw = dp[r - 1][i];
    }

    cout<<asw<<endl;

    return 0;
}

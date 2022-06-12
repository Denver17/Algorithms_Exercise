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

typedef long long ll;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        vector<vector<int> > vec;
        vector<vector<int> > dp;
        for(int i = 0; i < n; i++){
            vector<int> temp(i + 1);
            for(int j = 0; j < i + 1; j++){
                cin>>temp[j];
            }
            vec.push_back(temp);
        }
        dp = vec;
        for(int i = 1; i< vec.size(); i++){
            for(int j = 0; j < vec[i].size(); j++){
                if(j == 0)  dp[i][j] = dp[i - 1][j] + vec[i][j];
                else if(j == vec[i].size() - 1)     dp[i][j] = dp[i - 1][j - 1] + vec[i][j];
                else    dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + vec[i][j];
            }
        }
        ll asw = 0;
        for(int i = 0; i < dp.back().size(); i++){
            if(dp.back()[i] > asw)   asw = dp.back()[i];
        }
        cout<<asw<<endl;
    }

    return 0;
}
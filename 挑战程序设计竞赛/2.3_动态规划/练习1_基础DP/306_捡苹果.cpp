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

int T, W;
vector<int> vec;

int main()
{
    while(scanf("%d %d", &T, &W) != EOF){
        vec.resize(T);
        for(int i = 0; i < T; i++)  cin>>vec[i];
        vector<vector<int> > dp(T + 1, vector<int>(W + 1, 0));
        for(int i = 1; i <= T; i++){
            dp[i][0] = dp[i - 1][0] + (vec[i - 1] == 1 ? 1 : 0);
        }
        
        int asw = 0;
        for(int i = 1; i <= T; i++){
            for(int j = 1; j <= W; j++){
                int c;
                if(j % 2 == 0 && vec[i - 1] == 1)   c = 1;
                else if(j % 2 == 0 && vec[i - 1] == 2)  c = 0;
                else if(j % 2 == 1 && vec[i - 1] == 1)  c = 0;
                else    c = 1;
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + c;
                if(dp[i][j] > asw)  asw = dp[i][j];
            }
        }
        cout<<asw<<endl;
        vec.clear();
    }

    return 0;
}
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
    int n;  cin>>n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)  cin>>vec[i];
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(vec[j] < vec[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int asw = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] > asw) asw = dp[i];
    }
    cout<<asw<<endl;
    

    return 0;
}

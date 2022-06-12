#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<limits.h>
using namespace std;

int main()
{
    int K;  cin>>K;
    vector<int> vec(K);
    vector<int> dp(K);
    vector<int> left(K);
    int asw = INT_MIN,low = 0,high = 0;
    for(int i = 0; i < vec.size(); i++){
        cin>>vec[i];
    }
    dp[0] = vec[0];
    left[0] = 0;
    for(int i = 1; i < vec.size(); i++){
        dp[i] = max(dp[i-1]+vec[i],vec[i]);
        if(dp[i-1]+vec[i] >= vec[i]){
            left[i] = left[i-1];
        }
        else{
            left[i] = i;
        }
    }
    for(int i = 0; i < left.size(); i++){
        if(dp[i] > asw){
            asw = dp[i];
            low = left[i];
            high = i;
        }
    }
    if(asw < 0){
        cout<<0<<" "<<vec[0]<<" "<<vec.back();
    }
    else{
        cout<<asw<<" "<<vec[low]<<" "<<vec[high];
    }


    return 0;
}


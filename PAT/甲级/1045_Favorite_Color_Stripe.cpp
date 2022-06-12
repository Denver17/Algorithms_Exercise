#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<limits.h>
using namespace std;

vector<int> favorite;
vector<int> colors;
vector<int> dp;
vector<int> hashTable;

bool isValid(int num){
    if(hashTable[colors[num]] != INT_MAX)   return true;
    return false;
}

bool is_reasonable(int low,int high){
    int left = hashTable[colors[low]];
    int right = hashTable[colors[high]];
    if(left <= right)   return true;
    return false;
}

int main()
{
    int N;  cin>>N;
    int M;  cin>>M;
    hashTable.resize(N+1,INT_MAX);
    favorite.resize(M);
    for(int i = 0; i < M; i++){ 
        cin>>favorite[i];
        hashTable[favorite[i]] = i;
    }
    int L;  cin>>L;
    colors.resize(L);
    for(int i = 0; i < L; i++)  cin>>colors[i];
    
    int asw = -1;
    dp.resize(L);
    for(int i = 0; i < colors.size(); i++){
        dp[i] = 0;
        if(isValid(i)){     //颜色需要是Eva喜欢的
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(dp[j] != 0 && is_reasonable(j,i) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        asw = max(asw,dp[i]);
    }

    cout<<asw;

    return 0;
}


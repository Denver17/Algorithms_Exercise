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

struct interval{
    int start, end, efficiency;
};

bool cmp(interval a, interval b){
    return a.start < b.start;
}


int main()
{
    int N, M, R;
    while(scanf("%d %d %d", &N, &M, &R) != EOF){
        vector<interval> vec;
        for(int i = 0; i < M; i++){
            interval temp;
            scanf("%d %d %d", &temp.start, & temp.end, &temp.efficiency);
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end(), cmp);
        vector<int> dp(M);
        for(int i = 0; i < M; i++)  dp[i] = vec[i].efficiency;
        for(int i = 1; i < M; i++){
            for(int j = 0; j < i; j++){
                if(vec[j].end + R <= vec[i].start){
                    dp[i] = max(dp[i], dp[j] + vec[i].efficiency);
                }
            }
        }
        int asw = 0;
        for(int i = 0; i < M; i++){
            if(dp[i] > asw)     asw = dp[i];
        }
        printf("%d\n", asw);
    }

    return 0;
}
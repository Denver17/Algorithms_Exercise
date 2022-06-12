#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<limits.h>
using namespace std;

vector<int> dp;

int getsum(vector<int> &vec, int left, int right){
    int sum = 0;
    if(left == 0)   sum = dp[right];
    else{
        sum = dp[right] - dp[left - 1];
    }
    return sum;
}

int main()
{
    int N, M;   scanf("%d %d", &N, &M);
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &vec[i]);
    }

    dp.resize(N);
    dp[0] = vec[0];
    for(int i = 1; i < N; i++)  dp[i] += vec[i] + dp[i - 1];

    vector<int> asw;
    vector<int> asw2;
    int _min = INT_MAX;
    for(int i = 0; i < vec.size(); i++){
        int left = i, right = vec.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(getsum(vec, i, mid) == M){
                asw.push_back(i + 1);
                asw.push_back(mid + 1);
                break;
            }
            else if(getsum(vec, i, mid) < M){
                left = mid + 1;
            }
            else if(getsum(vec, i, mid) > M){
                right = mid - 1;
                int num = getsum(vec, i, mid);
                if(num < _min){
                    _min = num;
                    asw2.clear();
                    asw2.push_back(i + 1);
                    asw2.push_back(mid + 1);
                }
                else if(num == _min){
                    asw2.push_back(i + 1);
                    asw2.push_back(mid + 1);
                }
            }
        }
    }
    
    if(asw.size() == 0){
        for(int i = 0; i < asw2.size(); i += 2)    printf("%d-%d\n", asw2[i], asw2[i + 1]);
        return 0;
    }
    for(int i = 0; i < asw.size(); i += 2)  printf("%d-%d\n", asw[i], asw[i + 1]);

    return 0;
}


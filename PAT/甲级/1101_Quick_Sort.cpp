#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N;  scanf("%d", &N);
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &vec[i]);
    }
    vector<int> dp1(N);
    vector<int> dp2(N);
    dp1[0] = vec[0];
    for(int i = 1; i < N; i++){
        dp1[i] = max(vec[i], dp1[i - 1]);
    }
    
    dp2.back() = vec.back();
    for(int i = dp2.size() - 2; i >= 0; i--){
        dp2[i] = min(dp2[i + 1], vec[i]);
    }
    
    vector<int> asw;
    for(int i = 0; i < N; i++){
        if(vec[i] >= dp1[i] && vec[i] <= dp2[i])    asw.push_back(vec[i]);
    }

    printf("%d\n", asw.size());
    if(asw.size() == 0){
        printf("\n");
        return 0;
    }
    printf("%d", asw[0]);
    for(int i = 1; i < asw.size(); i++){
        printf(" %d", asw[i]);
    }

    return 0;
}


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<limits.h>
using namespace std;

int main()
{
    int N1; scanf("%d", &N1);
    vector<long long> vec1(N1);
    for(int i = 0; i < N1; i++){
        scanf("%lld", &vec1[i]);
    }
    int N2; scanf("%d", &N2);
    vector<long long> vec2(N2);
    for(int i = 0; i < N2; i++){
        scanf("%lld", &vec2[i]);
    }

    vec1.push_back(INT_MAX);
    vec2.push_back(INT_MAX);
    //int mid1 = (N1 - 1) / 2;
    //int mid2 = (N2 - 1) / 2;
    
    int left = 0, right = 0, _count = (N1 + N2 - 1) / 2;
    for(int i = 0; i < _count; i++){
        if(vec1[left] > vec2[right])    right++;
        else    left++;
    }

    long long asw = min(vec1[left], vec2[right]);
    printf("%lld", asw);

    return 0;
}


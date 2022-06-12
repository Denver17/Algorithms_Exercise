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

vector<int> vec;

bool judge(int d, int M){
    int cur = vec[0], ptr = 1;
    for(int i = 1; i < M; i++){
        while(ptr < vec.size() && vec[ptr] - d < cur)   ptr++;
        if(ptr >= vec.size())   return false;
        cur = vec[ptr++];
    }
    return true;
}

int main()
{
    int N, M;   cin>>N>>M;
    vec.resize(N);
    for(int i = 0; i < N; i++)  cin>>vec[i];
    sort(vec.begin(), vec.end());
    int left = 0, right = 0x3f3f3f3f;
    while(left < right - 1){
        int mid = left + (right - left) / 2;
        if(judge(mid, M))  left = mid;
        else    right = mid;
    }
    cout<<left<<endl;

    return 0;
}

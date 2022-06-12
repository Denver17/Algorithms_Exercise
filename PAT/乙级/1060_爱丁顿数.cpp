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
    sort(vec.begin(), vec.end());
    int asw = 0;
    for(int i = vec.size() - 1; i >= 0; i--){
        if(vec[i] > N - i) asw = N - i;
    }
    
    printf("%d", asw);

    return 0;
}


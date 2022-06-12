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

    int asw = (vec[0] + vec[1]) / 2;
    for(int i = 2; i < vec.size(); i++){
        asw = (asw + vec[i]) / 2;
    }

    printf("%d", asw);

    return 0;
}


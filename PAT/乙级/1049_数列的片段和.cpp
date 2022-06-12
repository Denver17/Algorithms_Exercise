//精度问题，要用long double
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N;  cin>>N;
    vector<long double> vec(N);
    for(int i = 0; i < N; i++){
        cin>>vec[i];
    }

    long double asw = 0;
    for(int i = 0; i < N; i++){
        asw += vec[i] * (i + 1) * (N - i);
    }

    printf("%.2Lf", asw);

    return 0;
}


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N;  cin>>N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin>>vec[i];
    }
    int cur = 0;
    int asw = 0;
    for(int i = 0; i < N; i++){
        if(vec[i] > cur){
            asw += (vec[i] - cur) * 6;
        }
        else{
            asw += (cur - vec[i]) * 4;
        }
        cur = vec[i];
        asw += 5;
    }

    cout<<asw;

    return 0;
}


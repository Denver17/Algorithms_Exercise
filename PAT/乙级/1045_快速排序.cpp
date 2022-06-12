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
    vector<int> dp1(N);
    vector<int> dp2(N);
    vector<int> asw;
    for(int i = 0; i < N; i++){
        cin>>vec[i];
    }
    dp1[0] = vec[0];
    for(int i = 1; i < N; i++){
        dp1[i] = max(vec[i], dp1[i - 1]);
    }
    dp2[N - 1] = vec[N - 1];
    for(int i = N - 2; i >= 0; i--){
        dp2[i] = min(vec[i], dp2[i + 1]);
    }
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] >= dp1[i] && vec[i] <= dp2[i])    asw.push_back(vec[i]);
    }
    cout<<asw.size()<<endl;
    if(asw.size() == 0){
        cout<<endl;
        return 0;
    }
    cout<<asw[0];
    for(int i = 1; i < asw.size(); i++) cout<<" "<<asw[i];

    return 0;
}


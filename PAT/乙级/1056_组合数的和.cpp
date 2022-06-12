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
    int asw = 0;
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec.size(); j++){
            if(i == j)  continue;
            int num = vec[i] * 10 + vec[j];
            asw += num;
        }
    }
    cout<<asw;

    return 0;
}


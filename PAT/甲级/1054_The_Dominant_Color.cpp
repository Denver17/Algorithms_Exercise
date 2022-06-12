#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
    int M,N;    cin>>M>>N;
    map<int,int> mp;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            int temp;   cin>>temp;
            mp[temp]++;
        }
    }
    int asw,_max = 0;
    for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
        if(it->second > _max){
            _max = it->second;
            asw = it->first;
        }
    }

    cout<<asw;

    return 0;
}


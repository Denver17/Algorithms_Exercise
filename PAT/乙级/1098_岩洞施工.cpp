#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N;  cin>>N;
    vector<int> top(N);
    vector<int> down(N);
    int _max = 0, _min = 1000;
    for(int i = 0; i < N; i++){
        cin>>top[i];
        if(top[i] < _min)   _min = top[i];
    }
    for(int i = 0; i < N; i++){
        cin>>down[i];
        if(down[i] > _max)  _max = down[i];
    }
    
    if(_max < _min){
        cout<<"Yes "<<abs(_max - _min)<<endl;
    }
    else{
        cout<<"No "<<abs(_max - _min) + 1<<endl;
    }


    return 0;
}


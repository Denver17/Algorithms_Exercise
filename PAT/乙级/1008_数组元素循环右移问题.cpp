#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin>>vec[i];
    }
    M = M % N;
    if( M == 0){
        cout<<vec[0];
        for(int i = 1; i < N; i++)  cout<<" "<<vec[i];
        return 0;
    }
    reverse(vec.begin() , vec.end() - M);
    reverse(vec.end() - M , vec.end());
    reverse(vec.begin() , vec.end());
    cout<<vec[0];
    for(int i = 1; i < N; i++)  cout<<" "<<vec[i];
    return 0;
}


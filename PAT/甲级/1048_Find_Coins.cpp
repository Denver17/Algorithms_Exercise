#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N,M;  cin>>N>>M;    
    vector<int> values(N);
    for(int i = 0; i < N; i++){
        cin>>values[i];
    }
    sort(values.begin(),values.end());
    int left = 0, right = values.size() - 1;
    while( left < right){
        if(values[left] + values[right] > M)    right--;
        else if(values[left] + values[right] < M)   left++;
        else if(values[left] + values[right] == M){
            cout<<values[left]<<" "<<values[right];
            return 0;
        }
    }

    cout<<"No Solution";

    return 0;
}


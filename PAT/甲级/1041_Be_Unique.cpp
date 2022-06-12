#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int main()
{
    int N;  cin>>N;
    int hashTable[10001] = {0};
    queue<int> que;
    for(int i = 0; i < N; i++){
        int num;    cin>>num;
        que.push(num);
        hashTable[num]++;
    }

    while(!que.empty()){
        int num = que.front();
        que.pop();
        if(hashTable[num] == 1){
            cout<<num;  return 0;
        }
    }

    cout<<"None";

    return 0;
}


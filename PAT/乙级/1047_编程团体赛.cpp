#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int N;  cin>>N;
    int hashTable[1001] = {0};
    for(int i = 0; i < N; i++){
        int team_num,member_num,grade;
        cin>>team_num;
        getchar();
        cin>>member_num>>grade;
        hashTable[team_num] += grade;
    }

    int _max = 0, num;
    for(int i = 0; i < 1000; i++){
        if(_max < hashTable[i]) { _max = hashTable[i];  num = i;}
    }

    cout<<num<<" "<<_max;

    return 0;
}


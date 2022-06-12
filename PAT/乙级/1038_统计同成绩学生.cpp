#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;



int main()
{
    int N;
    cin>>N;
    int hashTable[101] = {0};
    for(int i = 0; i < N; i++){
        int score;  cin>>score;
        hashTable[score]++;
    }

    int K;  cin>>K;
    int num;    cin>>num;
    cout<<hashTable[num];
    for(int i = 1; i < K; i++){
        int temp;   cin>>temp;
        cout<<" "<<hashTable[temp];
    }
    
    return 0;
}

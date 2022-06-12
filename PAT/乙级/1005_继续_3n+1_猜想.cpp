//哈希表的空间要足够大，不然可能会越界产生错误
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> hashTable(10000,0);
vector<int> hashTable2(10000,0);

void func(int num){
    if(num == 1)    return ;
    if(num % 2 == 0){
        num = num / 2;
        hashTable[num] = 1;
        func(num);
    }
    else{
        num = 3*num + 1;
        num = num / 2;
        hashTable[num] = 1;
        func(num);
    }
    return ;
}


int main()
{
    int K;  cin>>K;

    for(int i = 0; i < K; i++){
        int num;    cin>>num;
        hashTable2[num] = 1;
        func(num);
    }

    bool flag = false;
    for(int i = 100; i >= 2; i--){
        if( hashTable2[i] == 1 && hashTable[i] == 0 && flag == false){
            cout<<i;    flag = true;
        }
        else if( hashTable2[i] == 1 && hashTable[i] == 0 && flag == true){
            cout<<" "<<i;
        } 
    }


    return 0;
}


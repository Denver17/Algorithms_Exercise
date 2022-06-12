#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string str;  cin>>str;

    int hashTable[10] = {0};

    for(int i = 0; i < str.size(); i++){
        int temp = str[i] - '0';
        hashTable[temp]++;
    }
    
    for(int i = 0; i < 10; i++){
        if(hashTable[i] != 0){
            cout<<i<<":"<<hashTable[i]<<endl;
        }
    }

    return 0;
}


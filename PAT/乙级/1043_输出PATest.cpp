#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    string str;     cin>>str;
    int hashTable[6] = {0};
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'P')   hashTable[0]++;
        else if(str[i] == 'A')  hashTable[1]++;
        else if(str[i] == 'T')  hashTable[2]++;
        else if(str[i] == 'e')  hashTable[3]++;
        else if(str[i] == 's')  hashTable[4]++;
        else if(str[i] == 't')  hashTable[5]++;
    }

    while( !(hashTable[0] == 0 && hashTable[1] == 0 && hashTable[2] == 0
        && hashTable[3] == 0 && hashTable[4] == 0 && hashTable[5] == 0) ){
            if(hashTable[0] != 0)   { cout<<'P'; hashTable[0]--;}
            if(hashTable[1] != 0)   { cout<<'A'; hashTable[1]--;}
            if(hashTable[2] != 0)   { cout<<'T'; hashTable[2]--;}
            if(hashTable[3] != 0)   { cout<<'e'; hashTable[3]--;}
            if(hashTable[4] != 0)   { cout<<'s'; hashTable[4]--;}
            if(hashTable[5] != 0)   { cout<<'t'; hashTable[5]--;}
    }
    
    return 0;
}

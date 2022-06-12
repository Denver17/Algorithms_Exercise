#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string str;     cin>>str;
    int size = str.size();
    int n2,average;
    n2 = size;
    average = 1;
    while( n2 > average){
        n2 = n2 - 2;
        average++;
    }
    
    if(average == n2)   ;
    else    {n2 = n2 + 2;   average--;}

    for(int i = 0; i < average - 1; i++){    
        cout<<str[i];
        for(int j = 0; j < n2 - 2; j++) cout<<" ";
        cout<<str[size-i-1]<<endl;
    }
    for(int i = average - 1; i < n2 + average - 1; i++) cout<<str[i];
   

    return 0;
}


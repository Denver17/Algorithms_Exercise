#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool inspect(string str){
    for(int i = 0; i < str.size() - 1; i++){
        if(str[i] > '9' || str[i] < '0')    return false;
    }
    int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char check[11] = {'1' ,'0' ,'X' ,'9' ,'8' ,'7' ,'6' ,'5' ,'4' ,'3' ,'2'};
    int num = 0;
    for(int i = 0; i < str.size() - 1; i++){
        num += weight[i] * (str[i] - '0');
    }
    num = num % 11;
    
    if(check[num] == str[str.size() - 1])   return true;
    return false;
}

int main()
{
    int N;  cin>>N;
    bool flag = true;
    for(int i = 0; i < N; i++){
        string str;     cin>>str;
        if(inspect(str))    continue;
        else{
            cout<<str<<endl;
            flag = false;
        }
    }
    if(flag == false)   return 0;
    else cout<<"All passed"<<endl;

    return 0;
}


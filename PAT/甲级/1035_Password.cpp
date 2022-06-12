#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

bool check(string &str){
    bool flag = true;   //true表示未被更改
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '1')   { str[i] = '@'; flag = false;}
        else if(str[i] == '0')  { str[i] = '%'; flag = false; } 
        else if(str[i] == 'l')  { str[i] = 'L'; flag = false; }
        else if(str[i] == 'O')  { str[i] = 'o'; flag = false; }
    }
    return flag;
}

int main()
{
    int N;  cin>>N;
    vector<string> asw;
    for(int i = 0; i < N; i++){
        string name,password;
        cin>>name>>password;
        if( !check(password) ){
            asw.push_back(name);
            asw.push_back(password);
        }
    }
    
    if(asw.size() == 0){
        if(N == 1)  {cout<<"There is 1 account and no account is modified"; return 0;}
        else {cout<<"There are "<<N<<" accounts and no account is modified"; return 0;}
    }
    else{
        cout<<asw.size() / 2 <<endl;
        for(int i = 0; i < asw.size(); i++){
            cout<<asw[i]<<" ";
            i++;
            cout<<asw[i]<<endl;
        }
    }

    return 0;
}


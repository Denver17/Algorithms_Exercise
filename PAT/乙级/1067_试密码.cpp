//C语言输入string要分配空间，题目没说输入的字符串没有空格只说了密码没有空格所以要用getline
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string str; int N;
    cin>>str>>N;
    string input;
    input.resize(20);
    int _count = 0;
    getchar();
    while( getline(cin,input) ){
        if(input == "#")    break;
        if(input == str){
            printf("Welcome in\n");
            break;
        }
        else if(input != str){
            printf("Wrong password: %s\n",input.c_str());
            _count++;
            input.clear();
            if(_count == N){
                printf("Account locked\n");
                break;
            }
        }
    }

    return 0;
}


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int main()
{
    string str;     cin>>str;
    queue<char> qS;
    queue<char> qt;
    queue<char> qr;
    queue<char> qi;
    queue<char> qn;
    queue<char> qg;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'S')   qS.push(str[i]);
        else if(str[i] == 't')  qt.push(str[i]);
        else if(str[i] == 'r')  qr.push(str[i]);
        else if(str[i] == 'i')  qi.push(str[i]);
        else if(str[i] == 'n')  qn.push(str[i]);
        else if(str[i] == 'g')  qg.push(str[i]);
    }
    int _count = 0;
    while(!qS.empty() || !qt.empty() || !qr.empty() || !qi.empty() || !qn.empty() || !qg.empty() ){
        if(_count % 6 == 0 && !qS.empty()){
            cout<<"S";
            qS.pop();
        }
        else if(_count % 6 == 1 && !qt.empty()){
            cout<<"t";
            qt.pop();
        }
        else if(_count % 6 == 2 && !qr.empty()){
            cout<<"r";
            qr.pop();
        }
        else if(_count % 6 == 3 && !qi.empty()){
            cout<<"i";
            qi.pop();
        }
        else if(_count % 6 == 4 && !qn.empty()){
            cout<<"n";
            qn.pop();
        }
        else if(_count % 6 == 5 && !qg.empty()){
            cout<<"g";
            qg.pop();
        }
        _count++;
    }

    return 0;
}


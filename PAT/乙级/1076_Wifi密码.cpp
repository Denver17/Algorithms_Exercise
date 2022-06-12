#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    vector<int> asw;
    int N;  cin>>N;
    getchar();
    for(int i = 0; i < N; i++){
        string str;
        getline(cin, str);
        if(str[2] == 'T')   asw.push_back(str[0] - 'A' + 1);
        else if(str[6] == 'T')  asw.push_back(str[4] - 'A' + 1);
        else if(str[10] == 'T') asw.push_back(str[8] - 'A' + 1);
        else if(str[14] == 'T') asw.push_back(str[12] - 'A' + 1);
    }
    for(int i = 0; i < asw.size(); i++) cout<<asw[i];

    return 0;
}


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string str;     getline(cin,str);
    int size = str.size();
    vector<vector<int> > dp(size,vector<int> (size,0));
    int asw = 1;
    for(int i = 0; i < size; i++){
        dp[i][i] = 1;
        if(i < size - 1 && str[i] == str[i+1]){
            dp[i][i+1] = 1;
            asw = 2;
        }
    }
    for(int len = 3; len <= size; len++){
        for(int i = 0; i + len - 1 < size; i++){
            int j = i + len - 1;
            if(str[i] == str[j] && dp[i+1][j-1] == 1){
                dp[i][j] = 1;
                asw = len;
            }
        }
    }

    cout<<asw;

    return 0;
}


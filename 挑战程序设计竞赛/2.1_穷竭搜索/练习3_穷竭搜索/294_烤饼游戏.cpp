#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int asw = 0;

int getmax(vector<vector<int> > &vec){
    int res = 0;
    //遍历每一列
    for(int i = 0; i < vec[0].size(); i++){
        int num0 = 0, num1 = 0;
        for(int j = 0; j < vec.size(); j++){
            if(vec[j][i] == 0)  num0++;
            else    num1++;
        }
        res += max(num0, num1);
    }
    return res;
}

void changeRow(vector<vector<int> > &vec, int row){
    for(int i = 0; i < vec[row].size(); i++)    vec[row][i] = 1 - vec[row][i];
    return ;
}

void backtrack(vector<vector<int> > &vec, int row){
    if(row >= vec.size()){
        int res = getmax(vec);
        if(res > asw)   asw = res;
        return ;
    }
    //不翻转这一行
    backtrack(vec, row + 1);

    //翻转这一行
    changeRow(vec, row);
    backtrack(vec, row + 1);
    changeRow(vec, row);

    return ;
}

int main()
{
    int r, c;   
    while(cin>>r>>c){
        asw = 0;
        if(r == 0 && c == 0)    break;
        vector<vector<int> > vec(r, vector<int>(c));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin>>vec[i][j];
            }
        }
        
        backtrack(vec, 0);
        
        cout<<asw<<endl;
    }

    return 0;
}

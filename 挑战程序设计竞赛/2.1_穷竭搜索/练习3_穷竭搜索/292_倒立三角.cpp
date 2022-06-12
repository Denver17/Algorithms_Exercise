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

vector<bool> visited;

int S;

int getsum(vector<int> &vec){
    vector<int> pre = vec;
    for(int i = 1; i < vec.size(); i++){
        vector<int> temp;
        for(int j = 1; j < vec.size() - i + 1; j++){
            temp.push_back(pre[j - 1] + pre[j]);
        }
        pre.clear();    pre = temp;
    }
    return pre[0];
}

bool flag = false;

void backtrack(vector<int> &vec, int s, int n){
    if(flag == true)    return ;
    if(s == n){
        if(getsum(vec) == S){
            flag = true;
            cout<<vec[0];
            for(int j = 1; j < vec.size(); j++){
                cout<<" "<<vec[j];
            }
            cout<<endl;
        }
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(visited[i] == true)  continue;
        visited[i] = true;
        vec.push_back(i);
        backtrack(vec, s + 1, n);
        vec.pop_back();
        visited[i] = false;
    }
    return ;
}

int main()
{
    int n;   cin>>n>>S;
    vector<int> vec;
    visited.resize(n, false);
    backtrack(vec, 0, n);
    return 0;
}

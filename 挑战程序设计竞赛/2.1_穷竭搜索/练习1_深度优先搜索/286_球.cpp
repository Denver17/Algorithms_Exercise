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

vector<int> vec1;
vector<int> vec2;

bool dfs(vector<int> vec, int s){
    if(s == 10) return true;
    if(vec1.size() == 0 || vec[s] > vec1.back()){
        vec1.push_back(vec[s]);
        if(dfs(vec, s + 1))  return true;
        vec1.pop_back();
    }
    if(vec2.size() == 0 || vec[s] > vec2.back()){
        vec2.push_back(vec[s]);
        if(dfs(vec, s + 1))  return true;
        vec2.pop_back();
    }
    return false;
}

int main()
{
    int T;  cin>>T;
    for(int i = 0; i < T; i++){
        vec1.clear();
        vec2.clear();
        vector<int> vec(10);
        for(int j = 0; j < 10; j++){
            cin>>vec[j];
        }
        if(dfs(vec, 0)) cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    
    return 0;
}

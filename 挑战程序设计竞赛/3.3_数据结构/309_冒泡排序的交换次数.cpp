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

const int MAXN = 100000 + 100;

int n;
int bit[MAXN];

int sum(int i){
    int res = 0;
    while(i > 0){
        res += bit[i];
        i -= (i & -i);
    }
    return res;
}

void add(int i, int x){
    while(i <= n){
        bit[i] += x;
        i += (i & -i);
    }
}

int main()
{
    long long asw = 0;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++)  cin>>vec[i];
    for(int i = 0; i < n; i++){
        asw += i - sum(vec[i]);
        cout<<"sum "<<sum(vec[i])<<endl;
        add(vec[i], 1); 
    }
    cout<<asw<<endl;

    return 0;
}
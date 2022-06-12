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

const int MAXN = 5 * 100000 + 100;

int n, m;
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
    cin>>n>>m;
    int number[n + 1], pre[n + 1];
    for(int i = 1; i <= n; i++)     cin>>number[i];
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + number[i];
        bit[i] = pre[i] - pre[i - (i & -i)];
    }
    for(int i = 0; i < m; i++){
        int val;    cin>>val;
        if(val == 1){
            int x, k;   cin>>x>>k;
            add(x, k);
        }
        else{
            int x, y;   cin>>x>>y;
            cout<<sum(y) - sum(x - 1)<<endl;
        }
    }

    return 0;
}
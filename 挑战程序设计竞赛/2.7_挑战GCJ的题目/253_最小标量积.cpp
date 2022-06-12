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

typedef long long ll;

vector<ll> v1;
vector<ll> v2;

int main()
{
    int T;  cin>>T;
    for(int a = 0; a < T; a++){
        int n;  cin>>n;
        v1.resize(n);   v2.resize(n);
        for(int i = 0; i < n; i++)  cin>>v1[i];
        for(int i = 0; i < n; i++)  cin>>v2[i];
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        reverse(v2.begin(), v2.end());
        ll asw = 0;
        for(int i = 0; i < n; i++)  asw += v1[i] * v2[i];
        cout<<"Case #"<<a + 1<<": "<<asw<<endl;
    }
    

    return 0;
}

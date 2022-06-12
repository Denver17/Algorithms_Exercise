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

const int MAXN = 1000000 + 10;

vector<bool> p(MAXN, true);

int main()
{
    int n;  cin>>n;
    int asw = 0;
    p[1] = false;
    for(int i = 2; i <= n; i++){
        if(p[i] == true){
            for(int j = 2 * i; j <= n; j += i){
                p[j] = false;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(p[i] == true)    asw++;
    }

    cout<<asw<<endl;

    return 0;
}

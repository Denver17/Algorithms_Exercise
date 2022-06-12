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

const int INF = 1000000 + 10;

vector<bool> p(INF, true);
vector<int> res(INF, 0);

void init(){
    p[0] = false;
    p[1] = false;
    p[2] = true;
    for(int i = 2; i < INF; i++){
        if(p[i] == true){
            for(int j = 2 * i; j < INF; j += i){
                p[j] = false;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < INF; i++){
        if(p[i] == true)    sum++;
        res[i] = sum;
    }
    return ;
}

int main()
{
    int n;
    init();
    while(scanf("%d", &n) != EOF){
        cout<<res[n]<<endl;
    }

    return 0;
}
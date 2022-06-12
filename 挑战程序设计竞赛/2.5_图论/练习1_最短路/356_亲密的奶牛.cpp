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

const int MAXN = 300 + 10;
const int INF = 0x3f3f3f3f;

vector<vector<int> > f(MAXN, vector<int>(MAXN, INF));

void Floyd(int N){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    return ;
}

int main()
{
    for(int i = 0; i < MAXN; i++)   f[i][i] = 0;
    int N, M;   scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int k;  scanf("%d", &k);
        vector<int> temp(k);
        for(int j = 0; j < k; j++){
            scanf("%d", &temp[j]);
        }
        for(int x = 0; x < k - 1; x++){
            for(int y = x + 1; y < k; y++){
                f[temp[x]][temp[y]] = 1;
                f[temp[y]][temp[x]] = 1;
            }
        }
    }

    Floyd(N);

    double asw = (double)INF;
    for(int i = 1; i <= N; i++){
        double res = 0;
        for(int j = 1; j <= N; j++){
            if(f[i][j] != INF)  res += f[i][j];
        }
        res /= (N - 1);
        if(asw > res)   asw = res;
    }
    
    printf("%d", (int)(asw * 100));

    return 0;
}

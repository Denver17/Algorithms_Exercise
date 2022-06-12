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

const int MAXN = 200 + 10;
const int INF = 0x3f3f3f3f;

int f[MAXN][MAXN];
int mytime[MAXN];

void update(int k, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
    }
    return ;
}

int main()
{
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXN; j++){
            f[i][j] = INF;
        }
    }
    for(int i = 0; i < MAXN; i++)   f[i][i] = 0;
    int N, M;   scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &mytime[i]);
    }
    for(int i = 0; i < M; i++){
        int x, y, w;    scanf("%d %d %d", &x, &y, &w);
        f[x][y] = w;    f[y][x] = w;
    }

    int Q;  scanf("%d", &Q);
    int cur = 0;        //cur表示当前的村庄编号，随着编号递增，需要修复的天数也是递增的
    for(int i = 0; i < Q; i++){
        int x, y, t;    scanf("%d %d %d", &x, &y, &t);
        if(mytime[x] > t || mytime[y] > t)  printf("-1\n");
        else{
            while(mytime[cur] <= t && cur < N){
                update(cur, N);
                cur++;
            }
            if(f[x][y] == INF)  printf("-1\n");
            else    printf("%d\n", f[x][y]);
        }
    }

    return 0;
}

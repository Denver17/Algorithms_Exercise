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

const int MAXN = 150 + 10;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> P;

double f[MAXN][MAXN];
P pos[MAXN];

double getdist(int a, int b){
    return sqrt((pos[a].first - pos[b].first) * (pos[a].first - pos[b].first)
    + (pos[a].second - pos[b].second) * (pos[a].second - pos[a].second));
}

int main()
{
    int N;  scanf("%d", &N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            f[i][j] = INF;
        }
    }
    for(int i = 0; i < N; i++)  f[i][i] = 0;
    for(int i = 0; i < N; i++){
        int X, Y;   scanf("%d %d", &X, &Y);
        pos[i] = P(X, Y);
    }
    vector<vector<int> > G(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        int num;    scanf("%d", &num);
        vector<int> temp;
        for(int j = 0; j < N; j++){
            temp.push_back(num % 10);
            num /= 10;
        }
        reverse(temp.begin(), temp.end());
        G.push_back(temp);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(G[i][j] == 1){
                f[i][j] = getdist(i, j);
            }
        }
    }

    return 0;
}

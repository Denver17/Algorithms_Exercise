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

const int MAXN = 1000000 + 100;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int w, h, n;
vector<int> SX(MAXN), EX(MAXN), SY(MAXN), EY(MAXN);

int compress(vector<int>& X1, vector<int>& X2, int val){
    vector<int> res;
    for(int i = 0; i < n; i++){
        //线段的两端,以及线段中间,线段两端之外的空间都需要考虑
        for(int d = -1; d <= 1; d++){
            int tx1 = X1[i] + d, tx2 = X2[i] + d;
            if(1 <= tx1 && tx1 <= val)  res.push_back(tx1);
            if(1 <= tx2 && tx2 <= val)  res.push_back(tx2);
        }
    }

    //离散化
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    for(int i = 0; i < n; i++){
        X1[i] = find(res.begin(), res.end(), X1[i]) - res.begin();
        X2[i] = find(res.begin(), res.end(), X2[i]) - res.begin();
    }

    return res.size();
}

void solve(){
    int W = compress(SX, EX, w);
    int H = compress(SY, EY, h);
    vector<vector<bool> > visited(H, vector<bool>(W, false));
    for(int i = 0; i < n; i++){
        for(int y = SY[i]; y <= EY[i]; y++){
            for(int x = SX[i]; x <= EX[i]; x++){
                visited[y][x] = true;
            }
        }
    }

    int asw = 0;
    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            if(visited[y][x])   continue;
            asw++;

            queue<pair<int, int> > que;
            que.push(make_pair(x, y));
            while(!que.empty()){
                int sx = que.front().first, sy = que.front().second;
                que.pop();

                for(int i = 0; i < 4; i++){
                    int tx = sx + dx[i], ty = sy + dy[i];
                    if(tx < 0 || tx >= W || ty < 0 || ty >= H)  continue;
                    if(visited[ty][tx])     continue;
                    que.push(make_pair(tx, ty));
                    visited[ty][tx] = true;
                }
            }
        }
    }

    cout<<asw<<endl;
    return ;
}

int main()
{
    scanf("%d %d %d", &w, &h, &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &SX[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &EX[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &SY[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &EY[i]);
    }
    solve();

    return 0;
}
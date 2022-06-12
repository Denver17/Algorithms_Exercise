#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
    int N, M, TOL;   scanf("%d%d%d",&M,&N,&TOL);
    int X[8] = {0, 0, 1, -1, -1, -1, 1, 1};
    int Y[8] = {1, -1, 0, 0, -1, 1, -1, 1};
    int asw = -1, aswx, aswy;
    int val = 0;
    bool flag = false;
    vector<vector<int> > vec(N,vector<int>(M));
    map<int, int> mp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d",&vec[i][j]);
            mp[vec[i][j]]++;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(mp[vec[i][j]] != 1)  continue;
            int _count1 = 0, _count2 = 0;
            for(int k = 0; k < 8; k++){
                int newX = i + X[k];
                int newY = j + Y[k];

                if( !(newX >= 0 && newX < N && newY >= 0 && newY < M))  continue;
                _count1++;
                if(abs(vec[i][j] - vec[newX][newY]) > abs(TOL)){
                    _count2++;
                }
            }
            if(_count1 != _count2)  continue;
            
            if(flag == false){
                asw = vec[i][j];
                aswx = i + 1;   aswy = j + 1;
                flag = true;
            }
            else{
                printf("Not Unique");
                return 0;
            }
        }
    }
    if(asw == -1)   printf("Not Exist");
    else    printf("(%d, %d): %d", aswy, aswx, asw);

    return 0;
}


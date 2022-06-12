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

vector<vector<int> > asw;
vector<vector<int> > path;
vector<vector<vector<int> > > res;

int X[5] = {-1, 0, 1, 0, 0};
int Y[5] = {0, -1, 0, 1, 0};
int M, N;

bool cmp(vector<vector<int> > &a, vector<vector<int> > &b){
    string str1, str2;
    int res1 = 0, res2 = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            res1 += a[i][j];
            res2 += b[i][j];
            str1.push_back((char)(a[i][j] + '0'));
            str2.push_back((char)(b[i][j] + '0'));
        }
    }
    if(res1 != res2)    return res1 < res2;
    return str1 < str2;
}


void change(vector<vector<bool> >& vec, int row, int col){
    for(int i = 0; i < 5; i++){
        int newX = row + X[i], newY = col + Y[i];
        if(newX >= 0 && newX < M && newY >= 0 && newY < N){
            vec[newX][newY] = !vec[newX][newY];
        }
    }
    return ;
}

void solve(vector<vector<bool> > &vec, int N, int s){
    if(s == N){
        vector<vector<bool> > temp = vec;
        vector<vector<int> > tempPath = path;
        for(int i = 1; i < M; i++){
            for(int j = 0; j < N; j++){
                if(temp[i - 1][j] == true){
                    change(temp, i, j);
                    tempPath[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(temp[M - 1][i] != false)  return ;
        }
        res.push_back(tempPath);
        return ;
    }
    solve(vec, N, s + 1);

    change(vec, 0, s);
    path[0][s] = 1;
    solve(vec, N, s + 1);
    path[0][s] = 0;
    change(vec, 0, s);
    return ;
}

int main()
{
    cin>>M>>N;
    vector<vector<bool> > vec(M, vector<bool>(N));
    path.resize(M, vector<int>(N, 0));
    asw = path;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            int num;    cin>>num;
            if(num == 0)    vec[i][j] = false;
            else    vec[i][j] = true;
        }
    }
    solve(vec, N, 0);

    if(res.size() == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    sort(res.begin(), res.end(), cmp);
    asw = res[0];

    for(int i = 0; i < M; i++){
        cout<<asw[i][0];
        for(int j = 1; j < N; j++){
            cout<<" "<<asw[i][j];
        }
        cout<<endl;
    }
    return 0;
}

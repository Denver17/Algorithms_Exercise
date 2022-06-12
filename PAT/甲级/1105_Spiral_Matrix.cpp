#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> vec;
vector<int> factor;
vector<vector<int> > asw;
vector<vector<bool> > visited;

bool cmp(int a, int b){
    if(a != b)  return a > b;
}

void get_asw(int row, int col, int N){
    asw.resize(row, vector<int>(col));
    visited.resize(row, vector<bool>(col, false));
    int cnt = 0;
    int cur_row = 0, cur_col = 0;
    while(cnt < N){  
        for(; cur_col < col && visited[cur_row][cur_col] == false; cur_col++){
            asw[cur_row][cur_col] = vec[cnt++];
            visited[cur_row][cur_col] = true;
        }
        cur_col--;
        cur_row++;
        for(; cur_row < row && visited[cur_row][cur_col] == false; cur_row++){
            asw[cur_row][cur_col] = vec[cnt++];
            visited[cur_row][cur_col] = true;
        }
        cur_row--;
        cur_col--;
        for(; cur_col >= 0 && visited[cur_row][cur_col] == false; cur_col--){
            asw[cur_row][cur_col] = vec[cnt++];
            visited[cur_row][cur_col] = true;
        }
        cur_col++;
        cur_row--;
        for(; cur_row >= 0 && visited[cur_row][cur_col] == false; cur_row--){
            asw[cur_row][cur_col] = vec[cnt++];
            visited[cur_row][cur_col] = true;
        }
        cur_row++;
        cur_col++;
    }
    return ;
}

void get_fac(int N){
    for(int i = 1; i <= N; i++){
        if(N % i == 0)  factor.push_back(i);
    }
    return ;
}

int main()
{
    int N;  cin>>N;
    vec.resize(N);
    for(int i = 0; i < N; i++){
        cin>>vec[i];
    }

    sort(vec.begin(), vec.end(), cmp);
    
    int m, n;
    get_fac(N);
    int left = 0, right = factor.size() - 1;
    while(left <= right){
        if(factor[left] * factor[right] == N){
            m = factor[right];  n = factor[left];
        }
        right--;    left++;
    }

    get_asw(m, n, N);

    for(int i = 0; i < asw.size(); i++){
        cout<<asw[i][0];
        for(int j = 1; j < asw[i].size(); j++){
            cout<<" "<<asw[i][j];
        }
        cout<<endl;
    }

    return 0;
}


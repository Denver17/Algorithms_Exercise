#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<vector<int> > asw;

bool cmp(int a, int b){
    if(a != b)  return a > b;
}

bool isValid(int cur_row, int cur_col, int row, int col){
    if(cur_row >= 0 && cur_row < row && cur_col >= 0 && cur_col < col)  return true;
    return false;
}

void get_asw(vector<int> vec, int row, int col,vector<vector<bool> > visited){
    int size = vec.size();
    int cur_row = 0, cur_col = 0;
    for(int ptr = 0; ptr < size; ){
        while(isValid(cur_row,cur_col,row,col) && visited[cur_row][cur_col] == false){
            asw[cur_row][cur_col] = vec[ptr];
            visited[cur_row][cur_col] = true;
            cur_col++;  ptr++;
        }
        cur_col--;
        cur_row++;
        while(isValid(cur_row,cur_col,row,col) && visited[cur_row][cur_col] == false){
            asw[cur_row][cur_col] = vec[ptr];
            visited[cur_row][cur_col] = true;
            cur_row++;  ptr++;
        }
        cur_row--;
        cur_col--;
        while(isValid(cur_row,cur_col,row,col) && visited[cur_row][cur_col] == false){
            asw[cur_row][cur_col] = vec[ptr];
            visited[cur_row][cur_col] = true;
            cur_col--;  ptr++;
        }
        cur_col++;
        cur_row--;
        while(isValid(cur_row,cur_col,row,col) && visited[cur_row][cur_col] == false){
            asw[cur_row][cur_col] = vec[ptr];
            visited[cur_row][cur_col] = true;
            cur_row--;  ptr++;
        }
        cur_row++;
        cur_col++;
    }
    return ;
}

void display(){
    for(int i = 0; i < asw.size(); i++){
        cout<<asw[i][0];
        for(int j = 1; j < asw[i].size(); j++){
            cout<<" "<<asw[i][j];
        }
        cout<<endl;
    }
    return ;
}


int main()
{
    int N;  cin>>N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end(), cmp);
    
    vector<int> factor;
    for(int i = 1; i <= N; i++){
        if(N % i == 0)  factor.push_back(i);
    }
    int row, col;
    for(int right = factor.size() - 1 , left = 0; right >= left; ){
        if(factor[right] * factor[left] == N){
            row = factor[right];    col = factor[left];
            right--;    left++;
        }
        else if(factor[right] * factor[left] < N){
            left++;
        }
        else{
            right--;
        }
    }

    vector<vector<bool> > visited(row,vector<bool>(col,false));
    asw.resize(row,vector<int>(col));

    get_asw(vec,row,col,visited);

    display();

    return 0;
}


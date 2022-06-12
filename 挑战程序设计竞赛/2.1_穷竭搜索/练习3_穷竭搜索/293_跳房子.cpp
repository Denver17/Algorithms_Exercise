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

vector<vector<int> > vec(5, vector<int>(5));
//vector<vector<bool> > visited(5, vector<bool>(5, false));
set<string> st;
string path;

int X[4] = {0, -1, 0, 1};
int Y[4] = {-1, 0, 1, 0};

void backtrack(int cur_x, int cur_y, int len){
    if(len >= 6){
        st.insert(path);
        return ;
    }
    //visited[cur_x][cur_y] = false;
    path += char(vec[cur_x][cur_y] + '0');
    for(int i = 0; i < 4; i++){
        int newX = cur_x + X[i];
        int newY = cur_y + Y[i];
        if(newX >= 0 && newX < 5 && newY >= 0 && newY < 5){ //&& visited[newX][newY] == false){
            backtrack(newX, newY, len + 1);
        }
    }
    path.pop_back();
    //visited[cur_x][cur_y] = false;
    return ;
}


int main()
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin>>vec[i][j];
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            backtrack(i, j, 0);
        }
    }
    
    cout<<st.size()<<endl;

    return 0;
}

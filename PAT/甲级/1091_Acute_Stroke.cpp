#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int M,N,L,T;     //M，N是矩阵行数与列数，L是矩阵数目，T是阈值

int vec[61][1300][130];
//vector<bool> visited;
bool visited[61][1300][130] = {false};
int asw = 0;

struct node{
    int x;
    int y;
    int z;
};

bool test(int x,int y,int z){
    if(x >= L || x < 0 || y >= M || y < 0 || z >= N || z < 0)   return false;
    return true;
}

void BFS(int x,int y,int z,int &sum){
    int X[] = {1,-1,0,0,0,0};
    int Y[] = {0,0,1,-1,0,0};
    int Z[] = {0,0,0,0,1,-1};
    queue<node> que;
    node v; v.x = x;    v.y = y;    v.z = z;
    que.push(v);
    visited[x][y][z] = true;
    if(vec[x][y][z] == 1)   sum++;
    else    return ;
    while(que.size() != 0){
        node temp = que.front();
        que.pop();
        for(int i = 0; i < 6; i++){
            int newX = temp.x + X[i];
            int newY = temp.y + Y[i];
            int newZ = temp.z + Z[i];
            node newNode; newNode.x = newX; newNode.y = newY; newNode.z = newZ;
            if(test(newX,newY,newZ) && visited[newX][newY][newZ] == false && vec[newX][newY][newZ] == 1){
                sum++;
                que.push(newNode);
                visited[newX][newY][newZ] = true;
            }
        }
    }
    return ;
}

void BFSTraversal(){
    for(int i = 0; i < L; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                int sum = 0;
                if(visited[i][j][k] == false){
                    BFS(i,j,k,sum);
                }
                if(sum >= T) asw += sum;
            }
        }
    }
    return ;
}

int main()
{
    cin>>M>>N>>L>>T;
    for(int i = 0; i < L; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < N; k++){
                cin>>vec[i][j][k];
            }
        }
    }

    BFSTraversal();

    cout<<asw;

    return 0;
}

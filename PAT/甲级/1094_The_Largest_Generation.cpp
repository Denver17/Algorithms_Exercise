#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define maxn 100

int max_width = 0;
int depth = 0;

struct node{
    vector<int> children;
}Node[maxn];


void level_order(){
    queue<int> que;
    que.push(01);
    int cur_depth = 0;
    while(!que.empty()){
        cur_depth++;
        int size = que.size();
        if(size > max_width){
            max_width = size;
            depth = cur_depth;
        }
        for(int i = 0; i < size; i++){
            int num = que.front();
            que.pop();
            for(int j = 0; j < Node[num].children.size(); j++){
                que.push(Node[num].children[j]);
            }
        }
    }
    return ;
}



int main()
{
    int N;          //结点总数
    int M;          //非叶子结点数
    scanf("%d%d",&N,&M);
    for(int i = 0; i < M; i++){
        int ID;         //结点编号
        int K;          //结点拥有的孩子数
        scanf("%d%d",&ID,&K);
        for(int j = 0; j < K; j++){
            int temp;   //子节点编号
            scanf("%d",&temp);
            Node[ID].children.push_back(temp);
        }
    }
    level_order();

    printf("%d %d",max_width,depth);

    return 0;
}

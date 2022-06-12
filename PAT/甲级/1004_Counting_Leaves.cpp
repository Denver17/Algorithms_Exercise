
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

#define maxn 100

struct node{
    vector<int> children;
}Node[maxn];

vector<int> asw;

void level_order(){
    queue<int> que;
    que.push(01);
    while( !que.empty() ){
        int size = que.size();
        int _count = 0;
        for(int i = 0; i < size; i++){
            int num = que.front();
            que.pop();
            if(Node[num].children.size() == 0){     //若为叶节点
                _count++;
            }
            else{
                for(int j = 0; j < Node[num].children.size(); j++){
                    que.push(Node[num].children[j]);
                }
            }
        }
        asw.push_back(_count);
    }
    return ;
}

int main()
{
    int N;      //结点总数
    int M;      //非叶子结点数
    scanf("%d%d",&N,&M);
    for(int i = 0; i < M; i++){
        int node_num,K;         //node_num为结点编号,K为结点的孩子结点数
        scanf("%d%d",&node_num,&K);
        for(int j = 0; j < K; j++){
            int son_num;
            scanf("%d",&son_num);
            Node[node_num].children.push_back(son_num);
        }
    }
    level_order();

    for(int i = 0; i < asw.size(); i++){
        if(i != 0)  printf(" %d",asw[i]);
        else    printf("%d",asw[i]);
    }

    return 0;
}




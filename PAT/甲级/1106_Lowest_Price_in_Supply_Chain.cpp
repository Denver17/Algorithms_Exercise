#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

#define maxn 100000

double asw = 0;
int _count = 0;

struct node{
    
    vector<int> children;
}Node[maxn];

void level_order(double price,double percentage){
    queue<int> que;
    que.push(00);
    
    double cur_price = price;
    int flag = 0;
    while( !que.empty() && flag == 0){
        int size = que.size();
        for(int i = 0; i < size; i++){
            int node_num = que.front();
            que.pop();
            
            if(Node[node_num].children.size() == 0){        //找到叶子结点
                asw = cur_price;
                _count++;
                flag = 1;
            }
            for(int j = 0; j < Node[node_num].children.size(); j++){
                que.push(Node[node_num].children[j]);
            }
        }
        cur_price = cur_price * (1 + percentage);
    }
    return ;
}

int main()
{
    int N;              //结点总数
    double price;       //初始单价
    double percentage;  //提价百分比
    scanf("%d%lf%lf",&N,&price,&percentage);
    for(int i = 0; i < N; i++){
        int K;
        scanf("%d",&K);
        
        for(int j = 0; j < K; j++){
            int child_num;      //孩子结点编号
            scanf("%d",&child_num);
            Node[i].children.push_back(child_num);
        }
    }

    level_order(price,percentage*0.01);

    printf("%.4f %d",asw,_count);

    return 0;
}

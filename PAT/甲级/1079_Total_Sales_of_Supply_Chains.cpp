#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define maxn 100000

double asw = 0;

struct node{
    double single_price;    //产品单价
    double store_num;       //叶子结点上的产品数目
    vector<int> children;   //孩子结点
}Node[maxn];

void newNode(int index,double price){
    Node[index].single_price = price;
    Node[index].children.clear();
}

void dfs(int root,double price,double percentage){
    if(Node[root].children.size() == 0){    //若为叶节点
        asw += Node[root].store_num * price;
        return ;
    }
    for(int i = 0; i < Node[root].children.size(); i++){
        //double cur_price = price;       //保存当前单价，方便回溯
        dfs(Node[root].children[i],price * (1 + percentage),percentage);
    }
    return ;
}

int main()
{
    int N;                      //结点总数
    double unit_price;          //产品单价
    double percentage;          //提价百分比

    scanf("%d%lf%lf",&N,&unit_price,&percentage);

    for(int i = 0; i < N; i++){
        newNode(i,unit_price);
        int child_num;                          //每个节点的孩子结点数目
        scanf("%d",&child_num);
        Node[i].children.resize(child_num);     //这里注意分配空间，不然下面的children[j]访问不到内容...........................
        for(int j = 0; j < child_num; j++){
            scanf("%d",&Node[i].children[j]);   //孩子结点的编号
        }
        if(child_num == 0)                      //如果结点为叶子结点,孩子结点具有产品数目
            scanf("%lf",&Node[i].store_num);
    }

    dfs(0,unit_price,percentage*0.01);         //从根节点开始深度优先遍历

    printf("%.1f\n",asw);

    return 0;
}




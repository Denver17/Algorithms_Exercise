#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define maxn 100000

double asw = 0;
int _count = 0;

vector<vector<int>> vec;

struct node{
    double single_price;
    vector<int> children;
}Node[maxn];

void build_tree(vector<vector<int>> &vec,int root,double price,double percentage){
    Node[root].single_price = price;
    for(int i = 0; i < vec[root].size(); i++){
        Node[root].children.push_back(vec[root][i]);
    }
    if(price > asw){
        asw = price;
        _count = 1;
    }
    else if(price == asw){
        _count++;
    }
    for(int i = 0; i < Node[root].children.size(); i++){
        build_tree(vec,Node[root].children[i],price * (1 + percentage),percentage);
    }
    return ;
}


//本题需要将双亲表示法转化，用一维数组会超时，可以用二维数组进行操作
int main()
{
    int N;              //结点总数
    double P;           //根节点单价
    double percentage;  //提价百分比
    scanf("%d %lf %lf",&N,&P,&percentage);
   
    //vector<int> vec(N);
    int root = 0;
    vec.resize(N);
    for(int i = 0; i < N; i++){
        int temp;
        scanf("%d",&temp);
        if(temp == -1)    root = i;   //记录根节点下标
        else vec[temp].push_back(i); 
    }
    build_tree(vec,root,P,percentage*0.01);

    printf("%.2f %d",asw,_count);

    return 0;
}











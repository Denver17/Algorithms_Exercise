#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 110 

vector<vector<int>> asw;
vector<int> path;

struct node{
    int weight;
    vector<int> children;
}Node[maxn];

void newNode(int index,int val){
    Node[index].weight = val;
    Node[index].children.clear();
    return ;               
}

bool cmp(vector<int> a,vector<int> b){
    for(int i = 0; i < a.size() && i < b.size(); i++){
        if(a[i] != b[i])    return a[i] > b[i];
    }
    return a.size() < b.size();
}

void dfs(int root,int &sum,int target){
    if(sum == target && Node[root].children.size() == 0)   {asw.push_back(path);   return;}
    for(int i = 0; i < Node[root].children.size(); i++){
        sum += Node[Node[root].children[i]].weight;     //加上孩子的权重
        path.push_back(Node[Node[root].children[i]].weight);
        dfs(Node[root].children[i],sum,target);
        path.pop_back();
        sum -= Node[Node[root].children[i]].weight;     //回溯
    } 
    return ;
}

int main()
{
    int N;          //树中的结点总数
    int M;          //树中的非叶子结点数
    int S;          //目标数
    scanf("%d%d%d",&N,&M,&S);
    vector<int> vec;
    for(int i = 0; i < N; i++){
        int num;
        scanf("%d",&num);
        vec.push_back(num);
    }
    for(int i = 0; i < M; i++){
        int digit;      //结点编号
        int K;          //结点孩子个数
        scanf("%d%d",&digit,&K);
        newNode(digit,vec[digit]);
        for(int j = 0; j < K; j++){
            int child;
            scanf("%d",&child);
            Node[digit].children.push_back(child);
            Node[Node[digit].children[j]].weight = vec[Node[digit].children[j]];
        }
    }

    path.push_back(Node[00].weight);
    dfs(00,Node[00].weight,S);

    sort(asw.begin(),asw.end(),cmp);

    if(asw.size() == 0){
        cout<<vec[0]<<endl;
        return 0;
    }
    for(int i = 0; i < asw.size(); i++){
        for(int j = 0; j < asw[i].size(); j++){
            if(j != asw[i].size()-1)
                cout<<asw[i][j]<<" ";
            else
                cout<<asw[i][j]<<endl;
        }
    }
    return 0;
}


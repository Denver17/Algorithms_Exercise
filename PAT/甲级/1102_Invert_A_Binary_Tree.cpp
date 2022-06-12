#include<iostream>
#include<cstdio>
#include<vector>
#include<stdlib.h>
#include<queue>
using namespace std;

struct node{
    int val;
    struct node *left;
    struct node *right;
};

int root_num;
vector<int> in;

node* build_tree(vector<vector<int>> &tree,int root_num){
    node* root = new node;
    root->val = root_num;
    root->left = nullptr;   root->right = nullptr;
    if(tree[root_num][0] != -1) root->left = build_tree(tree,tree[root_num][0]);
    if(tree[root_num][1] != -1) root->right = build_tree(tree,tree[root_num][1]);
    return root;
}

void invert_tree(node* &root){
    if(root == nullptr) return ;
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invert_tree(root->left);
    invert_tree(root->right);
    return ;
}

void level_order(node* root){
    if(root==nullptr)   return ;
    queue<node*> que;
    que.push(root);
    while(!que.empty()){
        node* temp = que.front();
        que.pop();
        if(temp->left)  que.push(temp->left);
        if(temp->right) que.push(temp->right);
        if(temp != root)    printf(" %d",temp->val);
        else    printf("%d",temp->val);
    }
}

void in_order(node* root){
    if(root == nullptr) return ;
    in_order(root->left);
    in.push_back(root->val);
    in_order(root->right);
}


int main()
{
    int N;
    scanf("%d",&N);
    getchar();
    vector<vector<int>> tree(N,vector<int>(2));
    vector<int> res(N,-1);
    for(int i = 0; i < N; i++){
        char c1;
        scanf("%c",&c1);
        getchar();
        char c2;
        scanf("%c",&c2);
        getchar();
        if(c1 == '-')   tree[i][0] = -1;
        else    { tree[i][0] = (int)c1 - 48; res[(int)c1 - 48] = 0; }
        if(c2 == '-')   tree[i][1] = -1;
        else    { tree[i][1] = (int)c2 - 48; res[(int)c2 - 48] = 0; }
    }

    for(root_num = 0; root_num < N && res[root_num] == 0; root_num++);          //找到树的根节点
    node* root = build_tree(tree,root_num);
    invert_tree(root);
    level_order(root);
    printf("\n");
    in_order(root);
    printf("%d",in[0]);
    for(int i = 1; i < in.size(); i++)  printf(" %d",in[i]);
    return 0;
}

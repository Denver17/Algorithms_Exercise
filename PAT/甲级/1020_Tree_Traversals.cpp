#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

typedef struct node{
    int val;
    struct node *left;
    struct node *right;
}node,*tree;

node* build_tree(int postorder[],int pl,int ph,int inorder[],int il,int ih){
    node* root = new node;
    root->val = postorder[ph];
    root->left = nullptr;  root->right = nullptr; 
    //if(pl == ph)    return root;
    int i;
    for(i = il; inorder[i] != root->val; i++);      //找到中序序列中根节点的位置
    int left_len = i - il;
    int right_len = ih - i;
    if(left_len)    root->left = build_tree(postorder,pl,pl+left_len-1,inorder,il,il+left_len-1);
    if(right_len)    root->right = build_tree(postorder,pl+left_len,ph-1,inorder,il+left_len+1,ih);
    return root;
}

void level_order(node* root){
    if(root == nullptr) return ;
    queue<node*> que;
    que.push(root);
    while(!que.empty()){
        node* temp = que.front();
        que.pop();
        if(temp->left != nullptr)  que.push(temp->left);
        if(temp->right != nullptr) que.push(temp->right);
        if(que.size() == 0) printf("%d",temp->val);
        else    printf("%d ",temp->val);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    int postorder[N];
    int inorder[N];
    for(int i = 0; i < N; i++)  scanf("%d",&postorder[i]);
    for(int i = 0; i < N; i++)  scanf("%d",&inorder[i]);

    node* root = build_tree(postorder,0,N-1,inorder,0,N-1);
    level_order(root);
    return 0;
}





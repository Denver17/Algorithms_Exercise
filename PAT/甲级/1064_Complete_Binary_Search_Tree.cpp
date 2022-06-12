#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


struct node{
    int val;
    struct node *left;
    struct node *right;
};

node* build_complete_tree(int N){
    queue<node*> que;
    node* root = new node;
    root->val = -1;
    root->left = nullptr;   root->right = nullptr;
    que.push(root);
    N--;
    while( !que.empty()){
        node* temp = que.front();
        que.pop();
        if(N > 0){
            node* left_node = new node;
            left_node->val = -1;
            left_node->left = nullptr;  left_node->right = nullptr;
            temp->left = left_node;
            que.push(left_node);
        }
        N--;
        if(N > 0){
            node* right_node = new node;
            right_node->val = -1;
            right_node->left = nullptr; right_node->right = nullptr;
            temp->right = right_node;
            que.push(right_node);
        }
        N--;
    }
    return root;
}

void inorder(queue<int> &in_que,node* &root){
    if(root == nullptr) return ;
    inorder(in_que,root->left);
    root->val = in_que.front();
    in_que.pop();
    inorder(in_que,root->right);
    return;
}

void level_order(node* root,vector<int> &asw){
    if(root == nullptr) return;
    queue<node*> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; i++){
            node* temp = que.front();
            que.pop();
            asw.push_back(temp->val);
            if(temp->left)  que.push(temp->left);
            if(temp->right) que.push(temp->right);
        }
    }
    return ;
}



int main()
{
    int N;          //结点总数
    scanf("%d",&N);
    vector<int> asw;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        scanf("%d",&vec[i]);
    }
    
    sort(vec.begin(),vec.end());
    queue<int> in_que;
    for(int i = 0; i < vec.size(); i++) in_que.push(vec[i]);

    node* root = build_complete_tree(N);
    
    inorder(in_que,root);
    level_order(root,asw);

    printf("%d",asw[0]);
    for(int i = 1; i < asw.size(); i++){
        printf(" %d",asw[i]);
    }
    return 0;
}


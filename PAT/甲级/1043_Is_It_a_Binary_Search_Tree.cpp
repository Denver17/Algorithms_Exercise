#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

struct node{
    int val;
    struct node *left;
    struct node *right;
};

vector<int> origin,pre_order,mirror_pre_order,post_order,mirror_post_order;


void insert(node* &root,int num){
    if(root == nullptr){
        root = new node;
        root->val = num;
        root->left = nullptr;   root->right = nullptr;
        return ;
    }
    if(root->val > num) insert(root->left,num);
    else insert(root->right,num);
    return ;
}

void PreOrder(node* root){
    if(root == nullptr) return ;
    pre_order.push_back(root->val);
    PreOrder(root->left);
    PreOrder(root->right);
    return ;
}

void MPreOrder(node* root){
    if(root == nullptr) return ;
    mirror_pre_order.push_back(root->val);
    MPreOrder(root->right);
    MPreOrder(root->left);
    return ;
}

void PostOrder(node* root){
    if(root == nullptr) return ;
    PostOrder(root->left);
    PostOrder(root->right);
    post_order.push_back(root->val);
    return ;
}

void MPostOrder(node* root){
    if(root == nullptr) return ;
    MPostOrder(root->right);
    MPostOrder(root->left);
    mirror_post_order.push_back(root->val);
}



int main()
{
    int N;
    cin>>N;
    node* root = nullptr;
    for(int i = 0; i < N; i++){
        int num;    cin>>num;
        origin.push_back(num);
        insert(root,num);
    }
    
    PreOrder(root);
    MPreOrder(root);

    if(origin == pre_order || origin == mirror_pre_order){
        printf("YES\n");
        if(origin == pre_order){
            PostOrder(root);
            printf("%d",post_order[0]);
            for(int i = 1; i < N; i++){
                printf(" %d",post_order[i]);
            }
        }
        else{
            MPostOrder(root);
            printf("%d",mirror_post_order[0]);
            for(int i = 1; i < N; i++){
                printf(" %d",mirror_post_order[i]);
            }
        }
    }
    else{
        printf("NO\n");
    }
    return 0;
}

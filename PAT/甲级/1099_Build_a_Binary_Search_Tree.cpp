#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> asw;

struct node{
    int val;
    struct node *left;
    struct node *right;
};

node* build_tree(vector<vector<int>> &vec,int root_num){
    node* root = new node;
    root->left = nullptr;   root->right = nullptr;
    if(vec[root_num][0] == -1 && vec[root_num][1] == -1)    return root;
    if(vec[root_num][0] != -1)  root->left = build_tree(vec,vec[root_num][0]);
    if(vec[root_num][1] != -1)  root->right = build_tree(vec,vec[root_num][1]);
    return root;
}

void inorder(node* &root,queue<int> &in_que){
    if(root == nullptr) return ;
    inorder(root->left,in_que);
    root->val = in_que.front();
    in_que.pop();
    inorder(root->right,in_que);
    return ;
}

void levelorder(node* root){
    if(root == nullptr) return ;
    queue<node*> que;
    que.push(root);
    while( !que.empty() ){
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
    int N;
    scanf("%d",&N);
    vector<vector<int>> vec(N,vector<int>(2));
    vector<int> nums(N);
    for(int i = 0; i < N; i++){
        int left,right;
        scanf("%d%d",&left,&right);
        vec[i][0] = left;
        vec[i][1] = right;
    }
    for(int i = 0; i < N; i++)  scanf("%d",&nums[i]);
    
    node* root = build_tree(vec,0);

    sort(nums.begin(),nums.end());
    queue<int> in_que;
    for(int i = 0; i < N; i++) in_que.push(nums[i]);
    inorder(root,in_que);
    
    levelorder(root);

    printf("%d",asw[0]);
    for(int i = 1; i < N; i++){
        printf(" %d",asw[i]);
    }

    return 0;
}

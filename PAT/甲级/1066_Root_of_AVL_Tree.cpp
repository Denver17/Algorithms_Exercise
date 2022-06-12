#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


struct node{
    int val;
    struct node* left;
    struct node* right;
    int height;
};

node* newNode(int num){
    node* Node = new node;
    Node->val = num;
    Node->height = 1;
    Node->left = Node->right = nullptr;
    return Node;
}

int getHeight(node* root){
    if(root == nullptr) return 0;
    return root->height;
}

void updateHeight(node* &root){
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalancedFactor(node* root){
    return getHeight(root->left) - getHeight(root->right);
}

void L(node* &root){
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root){
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int num){
    if(root == nullptr){
        root = newNode(num);
        return ;
    }
    if(num < root->val){
        insert(root->left, num);
        updateHeight(root);
        
        if(getBalancedFactor(root) == 2){
            if(getBalancedFactor(root->left) == 1){     //LL
                R(root);
            }
            else if(getBalancedFactor(root->left) == -1){  //LR
                L(root->left);
                R(root);
            }
        }
    }
    else{
        insert(root->right, num);
        updateHeight(root);

        if(getBalancedFactor(root) == -2){
            if(getBalancedFactor(root->right) == -1){   //RR
                L(root);
            }
            else if(getBalancedFactor(root->right) == 1){    //RL
                R(root->right);
                L(root);
            }
        }
    }
}

node* create(vector<int> &vec){
    node* root = nullptr;
    for(int i = 0; i < vec.size(); i++){
        insert(root, vec[i]);
    }
    return root;
}


int main()
{
    int N;  cin>>N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin>>vec[i];
    }

    node* root = create(vec);

    printf("%d", root->val);

    return 0;
}


#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<string>
using namespace std;

struct node{
    int val;
    struct node *left;
    struct node *right;
};
vector<int> pre_order;
vector<int> in_order;
int root_val;

node* build_tree(int pl,int ph,int il,int ih){
    node* root = new node;
    root->val = pre_order[pl];
    root->left = nullptr;   root->right = nullptr;
    int pos;
    for(pos = 0; in_order[pos] != root->val; pos++);    //寻找中序遍历中根节点的位置
    int left_len = pos - il;
    int right_len = ih - pos;
    if(left_len != 0)   root->left = build_tree(pl+1,pl+left_len,il,il+left_len-1);
    if(right_len != 0)  root->right = build_tree(pl+left_len+1,ph,il+left_len+1,ih);
    return root;
}

void post_order(node* root){
    if(root == nullptr) return;
    post_order(root->left);
    post_order(root->right);
    if(root->val != root_val)
        printf("%d ",root->val);
    else    
        printf("%d",root->val);
    return;
}

int main()
{
    int N;
    scanf("%d",&N);

    stack<int> st;
    for(int i = 0; i < 2*N; i++){
        string str;
        cin >> str;
        string tmp = str.substr(0,3);
        if(tmp == "Pus"){
            int index;
            scanf("%d",&index);
            pre_order.push_back(index);
            st.push(index);
        }
        else if(tmp == "Pop"){
            int index = st.top();
            st.pop();
            in_order.push_back(index);
        }
    }  
    node* root = build_tree(0,N-1,0,N-1);
    root_val = pre_order[0];
    post_order(root);
    return 0;
}




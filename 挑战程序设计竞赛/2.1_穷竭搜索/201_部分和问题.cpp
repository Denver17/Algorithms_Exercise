#include<iostream>
#include<vector>
using namespace std;

vector<int> vec;
int sum = 0;
bool flag = false;

void DFS(int K, int start){
    if(start >= vec.size()) return ;
    for(int i = start; i < vec.size(); i++){
        sum += vec[i];
        if(sum == K)    flag = true;
        DFS(K, i + 1);
        sum -= vec[i];
    }
    return ;
}

int main()
{
    int n, k;
    while(cin>>n){
        vec.resize(n);
        for(int i = 0; i < n; i++){
            cin>>vec[i];
        }
        cin>>k;
        DFS(k, 0);
        if(flag == true)    cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
        flag = false;
    }

    return 0;
}
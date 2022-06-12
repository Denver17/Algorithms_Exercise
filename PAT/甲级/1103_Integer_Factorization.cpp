#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

vector<vector<int> > asw;
vector<vector<int> > asw2;
vector<int> path;

// int getsum(int P){
//     int sum = 0;
//     for(int i = 0; i < path.size(); i++){
//         sum += pow(path[i],P);
//     }
//     return sum;
// }

void get_max(){
    if(asw.size() == 0) return ;
    int _max = 0;
    for(int i = 0; i < asw.size(); i++){
        vector<int> vec;
        int sum = 0;
        for(int j = 0; j < asw[i].size(); j++){
            sum += asw[i][j];
            vec.push_back(asw[i][j]);
        }
        if(sum > _max){
            _max = sum;
            asw2.clear();
            asw2.push_back(vec);
        }
        else if(sum == _max){
            asw2.push_back(vec);
        }
    }
    return ;
}

void DFS(int N,int K,int P,int top,int sum){
    if(path.size() == K){
        if(sum == N)   asw.push_back(path);
        return ;
    }
    if(top == 0 || sum >= N)   return ;
    
    path.push_back(top);
    sum += pow(top,P);
    DFS(N,K,P,top,sum);
    sum -= pow(top,P);
    path.pop_back();
    
    DFS(N,K,P,top-1,sum);

    return ;
}

bool cmp(vector<int> a,vector<int> b){
    for(int i = 0; i < a.size() && i < b.size(); i++){
        if(a[i] != b[i])    return a[i] > b[i];
    }
}

int main()
{
    int N,K,P;  cin>>N>>K>>P;
    int top = sqrt(N);
    DFS(N,K,P,top,0);

    // for(int i = 0; i < asw.size(); i++){
    //     for(int j = 0; j < asw[i].size(); j++){
    //         if(j != asw[i].size() - 1)
    //             cout<<asw[i][j]<<" ";
    //         else
    //             cout<<asw[i][j]<<endl;
    //     }
    // }

    get_max();

    if(asw2.size() == 0){
        cout<<"Impossible";
        return 0;
    }
    else{
        sort(asw2.begin(),asw2.end(),cmp);
        cout<<N<<" = "<<asw2[0][0]<<"^"<<P;
        for(int i = 1; i < asw2[0].size(); i++){
            cout<<" + "<<asw2[0][i]<<"^"<<P;
        }
    }

    return 0;
}


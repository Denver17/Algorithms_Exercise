#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct node{
    int addr;
    int data;
    int next;
};

vector<node> list(1e5 + 10);

int main()
{
    int start, N, K;    scanf("%d %d %d", &start, &N, &K);

    vector<int> vec;
    for(int i = 0; i < N; i++){
        int adr;    scanf("%d", &adr);
        list[adr].addr = adr;
        scanf(" %d %d", &list[adr].data, &list[adr].next);
    }
    int tmpadr = start;
    while(tmpadr != -1){
        vec.push_back(tmpadr);
        tmpadr = list[tmpadr].next;
    }
    vector<vector<int> > res;
    
    for(int i = 0; i < vec.size(); i++){
        vector<int> temp;
        for(int j = 0; j < K; j++){
            if(i * K + j < vec.size())
                temp.push_back(vec[i * K + j]);
        }
        res.push_back(temp);
    }

    // cout<<"----------------"<<endl;
    // for(int i = 0; i < res.size(); i++){
    //     for(int j = 0; j < res[i].size(); j++){
    //         if(j != res[i].size() - 1)
    //             cout<<res[i][j]<<" ";
    //         else
    //             cout<<res[i][j]<<endl;
    //     }
    // }
    // cout<<"-----------------"<<endl;

    vector<vector<int> > asw;
    for(int i = res.size() - 1; i >= 0; i--) asw.push_back(res[i]);
    
    vector<int> asw2;
    for(int i = 0; i < asw.size(); i++){
        for(int j = 0; j < asw[i].size(); j++){
            asw2.push_back(asw[i][j]);
        }
    }

    for(int i = 0; i < asw2.size(); i++){
        if(i != asw2.size() - 1)    printf("%05d %d %05d\n", asw2[i], list[asw2[i]].data, asw2[i + 1]);
        else    printf("%05d %d %d\n", asw2[i], list[asw2[i]].data, -1);
    }

    return 0;
}


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
    int start, N, K;  scanf("%d %d %d", &start, &N, &K);
    for(int i = 0; i < N; i++){
        int adr;    scanf("%d", &adr);
        list[adr].addr = adr;
        scanf(" %d %d", &list[adr].data, &list[adr].next);
    }
    int tmpadr = start;
    vector<node> vec;
    while(tmpadr != -1){
        vec.push_back(list[tmpadr]);
        tmpadr = list[tmpadr].next;
    }
    vector<node> res;
    vector<node> res1;
    vector<node> res2;
    vector<node> res3;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i].data < 0){
            res1.push_back(vec[i]);
        }
        else if(vec[i].data >= 0 && vec[i].data <= K){
            res2.push_back(vec[i]);
        }
        else if(vec[i].data > K){
            res3.push_back(vec[i]);
        }
    }
    res.insert(res.end(), res1.begin(), res1.end());
    res.insert(res.end(), res2.begin(), res2.end());
    res.insert(res.end(), res3.begin(), res3.end());
    
    for(int i = 0; i < res.size(); i++){
        if(i != res.size() - 1){
            printf("%05d %d %05d\n", res[i].addr, res[i].data, res[i + 1].addr);
        }
        else{
            printf("%05d %d %d\n", res[i].addr, res[i].data, -1);
        }
    }

    return 0;
}


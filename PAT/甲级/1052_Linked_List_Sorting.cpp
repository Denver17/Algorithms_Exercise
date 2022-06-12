#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

const int maxn = 100010;

struct node{
    int pos;
    int key;
    int next;
}List[maxn];

bool cmp(node a,node b){
    if(a.key != b.key)  return a.key < b.key;
}

int main()
{
    int N,addr;   cin>>N>>addr;
    vector<node> vec;
    for(int i = 0; i < N; i++){
        int temp;   cin>>temp;
        List[temp].pos = temp;
        cin>>List[temp].key>>List[temp].next;
        //vec.push_back(List[temp]);
    }
    int adr = addr;
    while(adr != -1){
        vec.push_back(List[adr]);
        adr = List[adr].next;
    }
    sort(vec.begin(),vec.end(),cmp);
    if(vec.size() == 0){
        cout<<"0 -1";
        return 0;
    }
    printf("%d %05d\n",vec.size(),vec[0].pos);
    for(int i = 0; i < vec.size()-1; i++){
        printf("%05d %d %05d\n",vec[i].pos,vec[i].key,vec[i+1].pos);
    }
    printf("%05d %d -1",vec.back().pos,vec.back().key);


    return 0;
}


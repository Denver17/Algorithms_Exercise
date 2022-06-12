#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
using namespace std;

const int MAXN = 1e5 + 10;

struct node{
    string name;
    int ID;
    int weight;
    node(){
        name.resize(4);
        weight = 0;
    }
};

struct gang{
    string name;
    int size;
};

bool cmp(gang a, gang b){
    if(a.name != b.name)    return a.name < b.name;
}

vector<gang> asw;

vector<node> g(MAXN);
vector<node> adj[MAXN];
vector<bool> visited(MAXN, false);

int change(string str){
    int res = 0;
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.size(); i++){
        res += (int)(str[i] - 'A') * pow(10, i);
    }
    return res;
}

void dfs(int pos, int &sum, int &_max, vector<node> &vec, node &nres){
    sum += g[pos].weight;
    if(g[pos].weight > _max){
        nres = g[pos];
        _max = g[pos].weight;
    }
    vec.push_back(g[pos]);
    visited[pos] = true;
    for(int i = 0; i < adj[pos].size(); i++){
        if(visited[adj[pos][i].ID] == false){
            dfs(adj[pos][i].ID, sum, _max, vec, nres);
        }
    }
    return ;
}

void dfs_traversal(int N, int K){
    for(int i = 0; i < MAXN; i++){
        int sum = 0, _max = 0;
        vector<node> vec;
        node nres;
        if(visited[i] == false){
            dfs(i, sum, _max, vec, nres);
        }
        if(sum / 2 > K && vec.size() > 2){
            gang temp;  temp.name = nres.name;
            temp.size = vec.size();
            asw.push_back(temp);
        }
    }
    sort(asw.begin(), asw.end(), cmp);
    if(asw.size() == 0){
        printf("0");
    }
    else{
        printf("%d\n", asw.size());
        for(int i  = 0; i < asw.size(); i++){
            printf("%s %d\n", asw[i].name.c_str(), asw[i].size);
        }
    }
    return ;
}

int main()
{
    int N, K;   scanf("%d %d\n", &N, &K);

    for(int i = 0; i < N; i++){
        string str1, str2;  str1.resize(4);     str2.resize(4);
        int w;  
        //scanf("%s %s %d\n", str1.c_str(), str2.c_str(), &w);
        cin>>str1>>str2>>w;
        int v1 = change(str1);
        int v2 = change(str2);
        g[v1].ID = v1;  g[v1].name = str1;  g[v1].weight += w;
        g[v2].ID = v2;  g[v2].name = str2;  g[v2].weight += w;
        adj[v1].push_back(g[v2]);
        adj[v2].push_back(g[v1]);
    }

    dfs_traversal(N, K);
    


    return 0;
}


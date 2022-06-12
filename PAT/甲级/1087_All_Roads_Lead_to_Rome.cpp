#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
using namespace std;

const int MAXV = 200 + 10;
const int INF = 1e8;

struct node{
    int v;      //目标顶点编号
    int dis;    //边权
};


vector<int> d(MAXV);
vector<int> weit(MAXV);    //记录点权
vector<node> adj[MAXV];
vector<bool> visited(MAXV, false);
vector<int> pre[MAXV];
vector<int> num(MAXV);      //最短路条数

void Dijkstra(int s, int N){
    fill(d.begin(), d.end(), INF);
    fill(num.begin(), num.end(), 0);
    num[s] = 1;
    d[s] = 0;
    
    for(int i = 1; i <= N; i++){
        int u = -1, MIN = INF;
        for(int j = 1; j <= N; j++){
            if(visited[j] == false && d[j] < MIN){
                MIN = d[j];
                u = j;
            }
        }

        if(u == -1) return ;

        visited[u] = true;
        for(int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j].v;
            if(visited[v] == false && d[v] > d[u] + adj[u][j].dis){
                d[v] = d[u] + adj[u][j].dis;
                pre[v].clear();
                pre[v].push_back(u);
                num[v] = num[u];
            }
            else if(visited[v] == false && d[v] == d[u] + adj[u][j].dis){
                pre[v].push_back(u);
                num[v] += num[u];
            }
        }

    }

    return ;
}

int optValue = 0, optSize = 0;
vector<int> path, tempPath;
void DFS(int v, int s){
    if(v == s){
        tempPath.push_back(v);
        int value = 0;
        for(int i = 0; i < tempPath.size(); i++)    value += weit[tempPath[i]];
        if(value > optValue){
            optSize = tempPath.size();
            optValue = value;
            path = tempPath;
        }
        else if(value == optValue){
            if(tempPath.size() < optSize){
                optSize = tempPath.size();
                path = tempPath;
            }
        }
        tempPath.pop_back();
        return ;
    }

    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++){
        DFS(pre[v][i], s);
    }
    tempPath.pop_back();
}


int main()
{
    int N, K;   cin>>N>>K;
    string start;   cin>>start;
    map<string, int> city_index;
    map<int, string> index_city;

    int s = 1;
    city_index[start] = s;
    index_city[s] = start;
    for(int i = 0; i < N - 1; i++){
        string str; int weight;
        cin>>str>>weight;
        //int num = change(str);
        city_index[str] = i + 2;
        index_city[i + 2] = str;
        weit[i + 2] = weight;
    }
    
    for(int i = 0; i < K; i++){
        string str1, str2;  int distance;
        cin>>str1>>str2>>distance;
        int num1 = city_index[str1];
        int num2 = city_index[str2];
        node n1, n2;    n1.v = num1;    n2.v = num2;
        n1.dis = distance;  n2.dis = distance;
        adj[num1].push_back(n2);
        adj[num2].push_back(n1);
    }

    
    
    weit[s] = 0;
    Dijkstra(s, N);

    string destination = "ROM";
    int des = city_index[destination];
    DFS(des, s);

    cout<<num[des]<<" "<<d[des]<<" "<<optValue<<" "<<(int)(optValue / (path.size() - 1) )<<endl;
    cout<<start;
    for(int i = path.size() - 2; i >= 0; i--){
        cout<<"->"<<index_city[path[i]];
    }

    return 0;
}


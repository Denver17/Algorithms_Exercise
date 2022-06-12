#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

struct mouse{
    int weight;
    int rank;
};

vector<mouse> m;

int main()
{
    int N, K;   cin>>N>>K;
    m.resize(N);
    for(int i = 0; i < N; i++)  cin>>m[i].weight;

    queue<int> que;
    for(int i = 0; i < N; i++){
        int order;  cin>>order;
        que.push(order);
    }

    int temp = N;   int group;
    while(que.size() != 1){
        if(temp % K == 0)  group = temp / K;
        else    group = temp / K + 1;

        for(int i = 0; i < group; i++){
            int _max = que.front();            //存储最重的老鼠的编号
            for(int j = 0; j < K; j++){
                if(i * K + j >= temp)   break;
                int front = que.front();
                if(m[front].weight > m[_max].weight)   _max = front;
                m[front].rank = group + 1;
                que.pop();
            }
            que.push(_max);
        }
        temp = group;
    }

    m[que.front()].rank = 1;

    cout<<m[0].rank;
    for(int i = 1; i < m.size(); i++)   cout<<" "<<m[i].rank;


    return 0;
}


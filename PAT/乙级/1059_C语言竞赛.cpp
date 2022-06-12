#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

vector<int> prime;
vector<bool> p;
const int maxn = 1e4 + 10;

void getPrime(){
    prime.resize(maxn);
    p.resize(maxn,false);
    int ptr = 0;
    for(int i = 2; i <= maxn; i++){
        if(p[i] == false){
            prime[ptr++] = i;
            for(int j = i + i; j <= maxn; j += i){
                p[j] = true;
            }
        }
    }
}

int main()
{
    getPrime();
    int N;  cin>>N;
    map<int,int> mp;
    vector<int> vec(N);
    vector<bool> visited(maxn,false);
    vector<bool> existed(maxn,false);
    for(int i = 0; i < N; i++){
        cin>>vec[i];
        existed[vec[i]] = true;
        mp[vec[i]] = i + 1;
    }
    int K;  cin>>K;
    for(int i = 0; i < K; i++){
        int ID; cin>>ID;
        if(existed[ID] == false)        printf("%04d: Are you kidding?\n",ID);
        else if(visited[ID] == true)    printf("%04d: Checked\n",ID);
        else if(mp[ID] == 1){
            printf("%04d: Mystery Award\n",ID);
            visited[ID] = true;
        }
        else if(p[mp[ID]] == false){
            printf("%04d: Minion\n",ID);
            visited[ID] = true;
        }
        else{
            printf("%04d: Chocolate\n",ID);
            visited[ID] = true;
        }
    }

    return 0;
}


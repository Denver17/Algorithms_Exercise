#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
using namespace std;

bool cmp(int a, int b){
    if(a != b)  return a > b;
}

vector<int> father;

int findFather(int x){
    if(x == father[x])  return x;
    else{
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)  father[faA] = faB;
    return ;
}

int main()
{
    int N;  scanf("%d", &N);
    vector<set<int> > vec(N + 1);
    father.resize(N + 1);
    for(int i = 1; i <= N; i++){
        int K;
        scanf("%d:", &K);
        set<int> st;
        for(int j = 0; j < K; j++){
            int temp;
            scanf(" %d", &temp);
            st.insert(temp);
        }
        vec[i] = st;
        father[i] = i;
    }

    for(int i = 1; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            for(set<int>::iterator it = vec[j].begin(); it != vec[j].end(); it++){
                if(vec[i].count(*it) != 0){
                    Union(i, j);
                }
            }
        }
    }

    vector<int> res(N + 1, 0);
    vector<int> asw;
    for(int i = 1; i <= N; i++){
        res[findFather(i)] += 1;
    }

    for(int i = 1; i <= N; i++){
        if(res[i] != 0) asw.push_back(res[i]);
    }

    sort(asw.begin(), asw.end(), cmp);

    printf("%d\n", asw.size());
    if(asw.size() == 0) return 0;
    printf("%d", asw[0]);
    for(int i = 1; i < asw.size(); i++){
        printf(" %d", asw[i]);
    }    


    return 0;
}


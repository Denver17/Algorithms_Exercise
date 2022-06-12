//只是用map<int, int>是不行的，因为同一个物品编号可能出现多次
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;

int main()
{
    int N, M;   scanf("%d %d", &N, &M);
    map<int, set<int> > mp1;
    map<int, set<int> > mp2;
    for(int i = 0; i < N; i++){
        int num1, num2; scanf("%d %d", &num1, &num2);
        mp1[num1].insert(num2);
        mp2[num2].insert(num1);
    }
    for(int i = 0; i < M; i++){
        bool flag = true;
        int K;  scanf("%d", &K);
        vector<int> vec(K);
        set<int> st;
        for(int j = 0; j < K; j++){
            scanf(" %d", &vec[j]);
            st.insert(vec[j]);
        }
        for(int j = 0; j < K; j++){
            if(mp1.count(vec[j]) == 0 && mp2.count(vec[j]) == 0)  continue;
            else if(mp1.count(vec[j]) != 0){
                for(set<int>::iterator it = mp1[vec[j]].begin(); it != mp1[vec[j]].end(); it++){
                    if(st.count(*it) != 0)  flag = false;
                }
            }
            else if(mp2.count(vec[j]) != 0){
                for(set<int>::iterator it = mp2[vec[j]].begin(); it != mp2[vec[j]].end(); it++){
                    if(st.count(*it) != 0)  flag = false;
                }
            }     
        }
        if(flag == true)    printf("Yes\n");
        else    printf("No\n");
    }

    return 0;
}


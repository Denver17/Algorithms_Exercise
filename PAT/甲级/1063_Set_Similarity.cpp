#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int main()
{
    int N;  scanf("%d",&N);
    vector<set<int> > vec;
    for(int i = 0; i < N; i++){
        int M;  scanf("%d",&M);
        set<int> st;
        for(int j = 0; j < M; j++){
            int temp;   scanf("%d",&temp);
            st.insert(temp);
        }
        vec.push_back(st);
    }
    int K;  scanf("%d",&K);
    for(int i = 0; i < K; i++){
        int query1,query2;
        scanf("%d%d",&query1,&query2);
        query1--;   query2--;
        int common = 0,intersection = 0;
        set<int>::iterator it1 = vec[query1].begin();
        set<int>::iterator it2 = vec[query2].begin();
        while(it1 != vec[query1].end() && it2 != vec[query2].end()){
            if(*it1 == *it2){
                intersection++;
                common++;
                it1++;  it2++;
            }
            else if(*it1 < *it2){
                common++;
                it1++;
            }
            else{
                common++;
                it2++;
            }
        }
        while(it1 != vec[query1].end()){
            common++;
            it1++;
        }
        while(it2 != vec[query2].end()){
            common++;
            it2++;
        }
        double asw = (double)intersection / common * 100.0;
        printf("%.1f%%\n",asw);
    }
    

    return 0;
}


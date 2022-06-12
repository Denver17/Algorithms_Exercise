#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;

int main()
{
    int N;  cin>>N;
    map<int, int> mp;
    for(int i = 0; i < N; i++){
        int ID1, ID2;   cin>>ID1>>ID2;
        mp[ID1] = ID2;  mp[ID2] = ID1;
    }
    int M;  cin>>M;
    vector<int> asw;
    set<int> st;
    for(int i = 0; i < M; i++){
        int ID; cin>>ID;
        st.insert(ID);
        if(mp.count(ID) == 0)   mp[ID] = -1;
    }
    for(set<int>::iterator it = st.begin(); it != st.end(); it++){
        if(mp[*it] == -1)   asw.push_back(*it);
        else if(st.count(mp[*it]) == 0) asw.push_back(*it);
    }
    sort(asw.begin(), asw.end());
    cout<<asw.size()<<endl;
    if(asw.size() == 0) return 0;
    else{
        printf("%05d",asw[0]);
        for(int i = 1; i < asw.size(); i++) printf(" %05d",asw[i]);
    }
    return 0;
}


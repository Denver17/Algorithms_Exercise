#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
#include<map>
#include<set>
using namespace std;

int main()
{
    int N;  cin>>N;
    set<string> st;
    for(int i = 0; i < N; i++){
        string str;     str.resize(20);
        scanf("%s", str.c_str());
        st.insert(str);
    }
    int M; cin>>M;
    int asw = 0;
    map<string, int> mp;
    string oldest;
    int _min = 20991231;
    for(int j = 0; j < M; j++){
        string str; str.resize(20);
        scanf("%s", str.c_str());
        if(st.count(str) != 0)  asw++;
        mp[str] = atoi(str.substr(6, 8).c_str());
        if(st.count(str) != 0 && atoi(str.substr(6 ,8).c_str()) < _min){
            _min = atoi(str.substr(6 ,8).c_str());
            oldest = str;
        }
    }

    printf("%d\n", asw);
    if(asw != 0){
        printf("%s\n", oldest.c_str());
    }
    else{
        int temp = 20991231;
        for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
            if(it->second < temp){
                temp = it->second;
                oldest = it->first;
            }
        }
        printf("%s\n", oldest.c_str());
    }

    return 0;
}


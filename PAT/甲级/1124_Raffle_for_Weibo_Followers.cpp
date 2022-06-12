#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int main()
{
    int M, N, S;    cin>>M>>N>>S;
    set<string> st;
    vector<string> asw;
    int _count = 0;
    for(int i = 0; i < M; i++){
        string str; str.resize(20);
        scanf("%s",str.c_str());

        if(i + 1 < S)   continue;
        if(_count % N != 0) {
            _count++;
            continue;
        }
        if(st.count(str) != 0)  continue;
        asw.push_back(str);
        st.insert(str);
        _count++;
    }
    if(asw.size() == 0) printf("Keep going...");
    else{
        for(int i = 0; i < asw.size(); i++)
            printf("%s\n",asw[i].c_str());
    }    
    
    return 0;
}


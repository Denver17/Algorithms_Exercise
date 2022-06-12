#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int main()
{
    int N;  cin>>N;
    set<int> st;
    for(int i = 1; i <= N; i++){
        if(st.count(i / 2 + i / 3 + i / 5) == 0) st.insert(i / 2 + i / 3 + i / 5);
    }
    cout<<st.size()<<endl;

    return 0;
}


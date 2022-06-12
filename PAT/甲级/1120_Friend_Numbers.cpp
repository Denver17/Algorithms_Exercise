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
    for(int i = 0; i < N; i++){
        int num;    cin>>num;
        int res = 0;
        while(num != 0){
            res += num % 10;
            num = num / 10;
        }
        st.insert(res);
    }
    cout<<st.size()<<endl;
    set<int>::iterator it = st.begin();
    cout<<*it;
    for( it++; it != st.end(); it++){
        cout<<" "<<*it;
    }

    return 0;
}


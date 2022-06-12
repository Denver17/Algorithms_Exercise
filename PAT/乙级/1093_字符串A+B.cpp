#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int main()
{
    string A, B;
    getline(cin, A);
    getline(cin, B);
    set<char> st;
    string asw;
    for(int i = 0; i < A.size(); i++){
        if(st.count(A[i]) == 0){
            asw.push_back(A[i]);
            st.insert(A[i]);
        }
    }
    for(int i = 0; i < B.size(); i++){
        if(st.count(B[i]) == 0){
            asw.push_back(B[i]);
            st.insert(B[i]);
        }
    }
    printf("%s",asw.c_str());

    return 0;
}


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    unordered_set<char> st;

    for(int i = 0; i < str1.size(); i++)    transform(str1.begin(),str1.end(),str1.begin(),::toupper);
    for(int i = 0; i < str2.size(); i++)    transform(str2.begin(),str2.end(),str2.begin(),::toupper);

    int ptr1 = 0,ptr2 = 0,_count = 0;
    while( ptr2 < str2.size() ){
        if( str1[ptr1] != str2[ptr2] ){
            if(st.count(str1[ptr1]) == 0) {
                st.insert(str1[ptr1]);
                cout<<str1[ptr1];
            }
            ptr1++;
        }
        else{
            ptr1++; ptr2++;
        }
    }
    while( ptr1 < str1.size() ){
       if(st.count(str1[ptr1]) == 0) {
            st.insert(str1[ptr1]);
            cout<<str1[ptr1];
        }
        ptr1++;
    }

    return 0;
}

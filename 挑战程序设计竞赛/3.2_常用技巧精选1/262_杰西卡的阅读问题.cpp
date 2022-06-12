#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;


int main()
{
    int asw = 0x3f3f3f3f;
    int P;  scanf("%d", &P);
    vector<int> vec(P);
    for(int i = 0; i < vec.size(); i++)     scanf("%d", &vec[i]);
    vector<int> res(P + 1);
    set<int> st;
    for(int i = 0; i < vec.size(); i++){
        st.insert(vec[i]);
    }
    int size = st.size();
    int left = 0, right = 0;
    map<int, int> mp;
    while(true){
        while(right < vec.size() && mp.size() < size){
            mp[vec[right++]]++;
        }
        if(mp.size() < size)    break;
        asw = min(asw, right - left);
        mp[vec[left]]--;
        if(mp[vec[left]] == 0)  mp.erase(vec[left]);
        left++;
    }
    printf("%d\n", asw);
    return 0;
}

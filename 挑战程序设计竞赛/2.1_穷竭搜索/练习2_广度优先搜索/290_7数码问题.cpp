//这个状态转移应该从01234567这个初始状态转移到
//题目给出的数组状态，并且将求取过程的状态存储到
//map中方便查阅。不然题目测试数目过多造成超时
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cmath>
#include<stdlib.h>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool isEqual(vector<int> cur, vector<int> vec){
    for(int i = 0; i < vec.size(); i++){
        if(cur[i] != vec[i]) return false; 
    }
    return true;
}

map<vector<int>, int> mp;
vector<int> cur = {0, 1, 2, 3, 4, 5, 6, 7};

int BFS(vector<int> cur, vector<int> vec){
    int asw = 0;
    queue<vector<int> > que;
    set<vector<int> > st;
    que.push(cur);
    st.insert(cur);
    while(!que.empty()){
        int size = que.size();
        for(int k = 0; k < size; k++){
            vector<int> temp = que.front();
            que.pop();
            if(isEqual(temp, vec))   return asw;
            int x, y, i;
            for(i = 0; i < temp.size(); i++){
                if(temp[i] == 0){
                    x = i / 4;
                    y = i % 4;
                    break;
                }
            }
            if(x - 1 >= 0){
                vector<int> qtemp = temp;
                swap(qtemp[i - 4], qtemp[i]); 
                if(st.count(qtemp) == 0){
                    if(isEqual(qtemp, vec))   return asw + 1;
                    que.push(qtemp);
                    st.insert(qtemp);
                    mp[qtemp] = asw + 1;
                }
            }
            if(y + 1 < 4){
                vector<int> qtemp = temp;
                swap(qtemp[i + 1], qtemp[i]);
                if(st.count(qtemp) == 0){
                    if(isEqual(qtemp, vec))   return asw + 1;
                    que.push(qtemp);
                    st.insert(qtemp);
                    mp[qtemp] = asw + 1;
                }
            }
            if(x + 1 < 2){
                vector<int> qtemp = temp;
                swap(qtemp[i + 4], qtemp[i]);
                if(st.count(qtemp) == 0){
                    if(isEqual(qtemp, vec))   return asw + 1;
                    que.push(qtemp);
                    st.insert(qtemp);
                    mp[qtemp] = asw + 1;
                }
            }
            if(y - 1 >= 0){
                vector<int> qtemp = temp;
                swap(qtemp[i - 1], qtemp[i]);
                if(st.count(qtemp) == 0){
                    if(isEqual(qtemp, vec))   return asw + 1;
                    que.push(qtemp);
                    st.insert(qtemp);
                    mp[qtemp] = asw + 1;
                }
            }
        }
        asw++;
    }
    return asw;
}

int main()
{
    vector<int> vec(8);
    //while(cin>>vec[0]>>vec[1]>>vec[2]>>vec[3]>>vec[4]>>vec[5]>>vec[6]>>vec[7]){
    while(scanf("%d %d %d %d %d %d %d %d", &vec[0], &vec[1], &vec[2], &vec[3], &vec[4], &vec[5], &vec[6], &vec[7]) != EOF){
        if(mp.count(vec) == 1){
            cout<<mp[vec]<<endl;
            continue;
        }
        int asw = BFS(cur, vec);
        mp[vec] = asw;
        cout<<asw<<endl;
    }

    return 0;
}

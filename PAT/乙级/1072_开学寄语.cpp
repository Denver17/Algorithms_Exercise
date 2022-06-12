#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;

struct student{
    string name;
    vector<int> things;
};

int main()
{
    int N, M;   cin>>N>>M;
    set<int> st;
    vector<student> stu;
    int asw1 = 0, asw2 = 0;
    for(int i = 0; i < M; i++){
        int temp;   cin>>temp;
        st.insert(temp);
    }
    for(int i = 0; i < N; i++){
        string name;    int K;
        cin>>name>>K;
        vector<int> vec;
        for(int j = 0; j < K; j++){
            int temp;   cin>>temp;
            if(st.count(temp) != 0){
                asw2++;
                vec.push_back(temp);
            }
        }
        if(vec.size() == 0) continue;
        asw1++;
        cout<<name<<":";
        for(int j = 0; j < vec.size(); j++) printf(" %04d",vec[j]);
        printf("\n");
    }
    cout<<asw1<<" "<<asw2<<endl;

    return 0;
}


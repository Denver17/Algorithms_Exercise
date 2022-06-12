#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct student{
    string name;
    int height;
};

vector<student> stu;

bool cmp(student a, student b){
    if(a.height != b.height)    return a.height > b.height;
    else    return a.name < b.name;
}

int main()
{
    int N, K;   cin>>N>>K;
    stu.resize(N);
    for(int i = 0; i < N; i++){
        cin>>stu[i].name>>stu[i].height;
    }
    sort(stu.begin(), stu.end(), cmp);

    int col = N / K;
    int first_col = N / K + N % K;
    vector<vector<student> > asw(K);
    
    int ptr = 0;
    for(int i = 0; i < K; i++){
        if(i == 0)  asw[i].resize(first_col);
        else    asw[i].resize(col);
        int size = asw[i].size();
        asw[i][size / 2] = stu[ptr++];
        int left = size / 2 - 1, right = size / 2 + 1;
        while(left >= 0 || right < size){
            if(left >= 0)
                asw[i][left--] = stu[ptr++];
            if(right < size)
                asw[i][right++] = stu[ptr++];
        }
    }

    for(int i = 0; i < asw.size(); i++){
        cout<<asw[i][0].name;
        for(int j = 1; j < asw[i].size(); j++){
            cout<<" "<<asw[i][j].name;
        }
        cout<<endl;
    }

    return 0;
}


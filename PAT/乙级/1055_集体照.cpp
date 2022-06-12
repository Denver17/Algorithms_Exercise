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

bool cmp(student a, student b){
    if(a.height != b.height)    return a.height > b.height;
    return a.name < b.name;
}

int main()
{
    int N, K;  cin>>N>>K;
    vector<student> stu(N);
    for(int i = 0; i < N; i++){
        cin>>stu[i].name>>stu[i].height;
    }
    sort(stu.begin(), stu.end(), cmp);
    int sum = N;
    int ptr = 0;
    for(int i = 0; i < K; i++){
        int size;
        if(i == 0)  size = N / K + N % K;
        else size = N / K;
        sum = sum - size;
        if(size <= 0)    continue;
        vector<student> vec(size);
        vec[size / 2] = stu[ptr++];
        
        int left = size / 2 - 1, right = size / 2 + 1;
        while(left >= 0 || right < size){
            if(left >= 0){
                vec[left--] = stu[ptr++];
            }
            if(right < size){
                vec[right++] = stu[ptr++];
            }
        }
        cout<<vec[0].name;
        for(int i = 1; i < vec.size(); i++) cout<<" "<<vec[i].name;
        cout<<endl;
    }

    return 0;
}


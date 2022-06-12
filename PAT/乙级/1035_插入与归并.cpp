#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

vector<vector<int> > inst_asw;
vector<vector<int> > merge_asw;

void insert_sort(vector<int> &vec){
    int size = vec.size();
    for(int i = 1; i < size; i++){
        int temp = vec[i], j = i;
        while(j > 0 && temp < vec[j - 1]){
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = temp;
        inst_asw.push_back(vec);
    }
    return ;
}

void merge(vector<int> &vec, int L1, int R1, int L2, int R2){
    int i = L1, j = L2;
    vector<int> temp;
    while(i <= R1 && j <= R2){
        if(vec[i] <= vec[j]){
            temp.push_back(vec[i++]);
        }
        else{
            temp.push_back(vec[j++]);
        }
    }
    while(i <= R1)  temp.push_back(vec[i++]);
    while(j <= R2)  temp.push_back(vec[j++]);
    for(int k = 0; k < temp.size(); k++){
        vec[L1 + k] = temp[k];
    }
    return ;
}

void merge_sort(vector<int> &vec, int left, int right){
    for(int step = 2; step / 2 <= vec.size(); step *= 2){
        for(int i = 0; i < vec.size(); i += step){
            int mid = i + step / 2 - 1;
            if(mid + 1 < vec.size()){
                merge(vec, i, mid, mid + 1, min(i + step - 1, (int)vec.size() - 1));
            }
            //sort(vec.begin() + i, vec.begin() + min( i + step, (int)vec.size()));
        }
        merge_asw.push_back(vec);
    }
    return ;
}


int main()
{
    int N;  scanf("%d", &N);
    vector<int> vec(N);
    vector<int> qes(N);
    for(int i = 0; i < N;i ++){
        scanf("%d", &vec[i]);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &qes[i]);
    }

    vector<int> vec1 = vec;
    vector<int> vec2 = vec;

    insert_sort(vec1);
    merge_sort(vec2, 0, vec2.size() - 1);

    sort(vec.begin(), vec.end());
    inst_asw.push_back(vec);
    merge_asw.push_back(vec);
    
    for(int i = 0; i < inst_asw.size(); i++){
        if(inst_asw[i] == qes){
            printf("Insertion Sort\n");
            printf("%d", inst_asw[i + 1][0]);
            for(int j = 1; j < inst_asw[i + 1].size(); j++){
                printf(" %d", inst_asw[i + 1][j]);
            }
            return 0;
        }
    }
    
    for(int i = 0; i < merge_asw.size(); i++){
        if(merge_asw[i] == qes){
            printf("Merge Sort\n");
            printf("%d", merge_asw[i + 1][0]);
            for(int j = 1; j < merge_asw[i + 1].size(); j++){
                printf(" %d", merge_asw[i + 1][j]);
            }
            return 0;
        }
    }

    return 0;
}


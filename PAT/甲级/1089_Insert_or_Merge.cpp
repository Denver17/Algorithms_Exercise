#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<vector<int> > instvec;
vector<vector<int> > mergevec;

void instsort(vector<int> &vec){
    for(int i = 1; i < vec.size(); i++){
        int j = i, temp = vec[i];
        while(j > 0 && vec[j - 1] > temp){
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = temp;
        instvec.push_back(vec);
    }
    return ;
}

void merge(vector<int> &vec, int L1, int R1, int L2, int R2){
    int left = L1, right = L2;
    vector<int> temp;
    while(left <= R1 && right <= R2){
        if(vec[left] <= vec[right]){
            temp.push_back(vec[left++]);
        }
        else{
            temp.push_back(vec[right++]);
        }
    }
    while(left <= R1)   temp.push_back(vec[left++]);
    while(right <= R2)  temp.push_back(vec[right++]);

    for(int i = 0; i < temp.size(); i++)    vec[L1 + i] = temp[i];
    return ;
}

void mergesort(vector<int> &vec){
    for(int step = 2; step / 2 <= vec.size(); step *= 2){
        for(int i = 0; i < vec.size(); i += step){
            int mid = i + step / 2 - 1;
            if(mid + 1 < vec.size()){
                merge(vec, i, mid, mid + 1, min(i + step - 1, (int)vec.size() - 1));
            }
        }
        mergevec.push_back(vec);
    }
    return ;
}

int main()
{
    int N;  cin>>N;
    vector<int> vec1(N);
    vector<int> vec2(N);
    vector<int> qes(N);
    for(int i = 0; i < N; i++){
        cin>>vec1[i];
        vec2[i] = vec1[i];
    }
    for(int i = 0; i < N; i++){
        cin>>qes[i];
    }
    
    //instvec.push_back(vec1);
    //mergevec.push_back(vec2);
    instsort(vec1);
    mergesort(vec2);
    instvec.push_back(vec1);
    mergevec.push_back(vec2);

    for(int i = 0; i < instvec.size(); i++){
        if(instvec[i] == qes){
            cout<<"Insertion Sort"<<endl;
            for(int j = 0; j < instvec[i + 1].size(); j++){
                if(j == 0)  cout<<instvec[i + 1][j];
                else    cout<<" "<<instvec[i + 1][j];
            }
        }
    }

    for(int i = 0; i < mergevec.size(); i++){
        if(mergevec[i] == qes){
            cout<<"Merge Sort"<<endl;
            for(int j = 0; j < mergevec[i + 1].size(); j++){
                if(j == 0)  cout<<mergevec[i + 1][j];
                else    cout<<" "<<mergevec[i + 1][j];
            }
        }
    }


    return 0;
}


#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

vector<int> A2,A4;

int main()
{
    int N;
    cin>>N;
    int asw1 = 0;
    int asw2 = 0;
    int asw3 = 0;
    double asw4 = 0;
    int asw5 = 0;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin>>vec[i];
    }
    for(int i = 0; i < N; i++){
        if(vec[i] % 5 == 0 && vec[i] % 2 == 0)  asw1 += vec[i];
        if(vec[i] % 5 == 1) A2.push_back(vec[i]);
        if(vec[i] % 5 == 2) asw3++; 
        if(vec[i] % 5 == 3) A4.push_back(vec[i]);
        if(vec[i] % 5 == 4 && vec[i] > asw5)    asw5 = vec[i];
    }
    for(int i = 0; i < A2.size(); i++){
        if( i % 2 == 0) asw2 += A2[i];
        else asw2 -= A2[i];
    }
    double sum = 0;
    for(int i = 0; i < A4.size(); i++){
        sum += A4[i];
    }
    if(A4.size() != 0) asw4 = sum / A4.size();
    

    if(asw1 == 0)   cout<<"N ";
    else cout<<asw1<<" ";

    if(A2.size() == 0)   cout<<"N ";
    else cout<<asw2<<" ";

    if(asw3 == 0)   cout<<"N ";
    else cout<<asw3<<" ";

    if(asw4 == 0)    cout<<"N ";
    else printf("%.1lf ",asw4);

    if(asw5 == 0)   cout<<"N";
    else cout<<asw5;


    return 0;
}

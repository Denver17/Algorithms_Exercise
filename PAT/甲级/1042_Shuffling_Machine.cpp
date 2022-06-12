#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

vector<string> vec = 
    {   
        "S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
        "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
        "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
        "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
        "J1","J2"
    };

int main()
{
    int K;
    cin>>K;
    int size = vec.size();
    vector<int> order(size);
    for(int i = 0; i < order.size(); i++){
        cin>>order[i];
    }
    vector<string> asw(size);
    for(int i = 0; i < K; i++){
        for(int j = 0; j < vec.size(); j++){
            asw[order[j] - 1] = vec[j];
        }
        vec = asw;
    }

    cout<<asw[0];
    for(int i = 1; i < asw.size(); i++){
        cout<<" "<<asw[i];
    }


    return 0;
}

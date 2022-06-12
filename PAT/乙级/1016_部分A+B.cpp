#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    string A,DA,B,DB;
    string temp1,temp2;
    int res1,res2;
    cin>>A>>DA>>B>>DB;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==DA[0])
            temp1.push_back(DA[0]);
    }
    for(int i=0;i<B.size();i++)
    {
        if(B[i]==DB[0])
            temp2.push_back(DB[0]);
    }
    res1=atoi(temp1.c_str());
    res2=atoi(temp2.c_str());
    cout<<res1+res2<<endl;

    return 0;
}
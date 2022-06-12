#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

int shalou(int N)
{
    if(N==1)
        return 1;
    else
    {
        return 1+2*(N-1)*(N+1);
    }
}

void sha_print(int num,char c)
{
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<num-i-1;j++)
        {
            cout<<c;
        }
        cout<<c;
        for(int j=0;j<num-i-1;j++)
        {
            cout<<c;
        }
        // for(int j=0;j<i;j++)
        // {
        //     cout<<" ";
        // }
        cout<<endl;
    }
    for(int i=1;i<num;i++)
    {
        for(int j=0;j<num-1-i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<i;j++)
        {
            cout<<c;
        }
        cout<<c;
        for(int j=0;j<i;j++)
        {
            cout<<c;
        }
        // for(int j=0;j<num-1-i;j++)
        // {
        //     cout<<" ";
        // }
        cout<<endl;
    }
}


int main()
{
    int N;
    char c;
    cin>>N>>c;

    int num=1;
    while(shalou(num)<N)
    {
        num++;
    }
    if(shalou(num)==N)
    {
        sha_print(num,c);
        cout<<0<<endl;
    }
    else
    {
        sha_print(num-1,c);
        cout<<N-shalou(num-1)<<endl;
    }

    return 0;
}

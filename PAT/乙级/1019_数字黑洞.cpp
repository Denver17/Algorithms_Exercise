#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

string up(int N)
{
    string temp;
    int a[4]={0,0,0,0};
    for(int i=0;i<4;i++)
    {
        a[i]=N%10;
        N=N/10;
    }
    sort(a,a+4);
    char cao;       //直接使用char，方便调用push_back
    
    cao=a[0]+'0';
    temp.push_back(cao);

    cao=a[1]+'0';
    temp.push_back(cao);

    cao=a[2]+'0';
    temp.push_back(cao);

    cao=a[3]+'0';
    temp.push_back(cao);

    return temp;
}

string down(int N)
{
    string temp;
    int a[4]={0,0,0,0};
    for(int i=0;i<4;i++)
    {
        a[i]=N%10;
        N=N/10;
    }
    sort(a,a+4);
    char cao;
    
    cao=a[3]+'0';
    temp.push_back(cao);

    cao=a[2]+'0';
    temp.push_back(cao);

    cao=a[1]+'0';
    temp.push_back(cao);

    cao=a[0]+'0';
    temp.push_back(cao);

    return temp;
}

int calculate(int N)
{
    if(N==6174)
    {
        return 0;
    }
    
    int temp=atoi(down(N).c_str())-atoi(up(N).c_str());
    if(temp==0)
    {
        cout<<N<<" - "<<N<<" = "<<"0000"<<endl;
        return 0;
    }
    if(temp>0&&temp<10)
        cout<<down(N)<<" - "<<up(N)<<" = 000"<<temp<<endl;
    if(temp>=10&&temp<100)
        cout<<down(N)<<" - "<<up(N)<<" = 00"<<temp<<endl;
    if(temp>=100&&temp<1000)
        cout<<down(N)<<" - "<<up(N)<<" = 0"<<temp<<endl;
    if(temp>=1000)
        cout<<down(N)<<" - "<<up(N)<<" = "<<temp<<endl;
    
    calculate(temp);
    
    return 0;
}


int main()
{
    int N;
    cin>>N;
    if(N!=6174)     //6174本身，特殊情况
        calculate(N);
    else
        cout<<down(N)<<" - "<<up(N)<<" = "<<6174<<endl;
    return 0;
}


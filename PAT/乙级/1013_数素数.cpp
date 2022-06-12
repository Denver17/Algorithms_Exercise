#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> res;

bool is_prime(int num)
{
    if(num==2||num==3)
        return 1;
    if(num%2==0)
        return 0;
    for(int i=2;i<=(int)sqrt(num);i++)
    {
        if(num%i==0)
            return 0;
    }
    return 1;
}

int find_prime(int num)
{
    int tag=1;
    int n=2;
    res.push_back(2);
    while(tag<=num)
    {
        while(!(is_prime(++n)))
        {
            continue;
        }
        res.push_back(n);
        tag++;
    }
    return n;
}

int main()
{
    int M,N;
    cin>>M>>N;
    find_prime(N);
    for(int i=M-1;i<res.size()-1;i++)
    {
        if((i-M+2)%10==0&&i!=M-1)
            cout<<res[i]<<endl;
        else if(i<res.size()-2)
            cout<<res[i]<<" ";
        else if(i==res.size()-2)
            cout<<res[i]<<endl;
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool is_prime(int num)
{
    // 两个较小的数另外处理
    if(num == 2 || num == 3)
    {
        return 1;
    }
    // 不在6的倍数的两侧的一定不是素数
    if(num % 6 != 1 && num % 6 != 5)
    {
        return 0;
    }
    int tem = (int)sqrt(num);
    //在6的倍数的两侧的也不一定是素数
    for(int i = 5;i <= tem;i += 6)
    {
        if(num % i == 0 || num % (i + 2) == 0)
        {
            return 0;
        }
    }
    // 排除所有剩余的是素数
    return 1;
}

int main()
{
    int N;
    cin>>N;
    vector<int>res;
    vector<int>asw;
    if(N>3)
    {
        res.push_back(2);
        res.push_back(3);
        for(int i=5;i<=N;i+=2)
        {
            if(is_prime(i))
                res.push_back(i);
        }
        for(int i=0;i<res.size();i++)
        {
            if(res[i+1]-res[i]==2)
            {
                asw.push_back(i);
            }
        }
        cout<<asw.size()<<endl;
    }
    else
        cout<<0<<endl;

    return 0;
}

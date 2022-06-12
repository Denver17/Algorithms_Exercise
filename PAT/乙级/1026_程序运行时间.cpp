#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main()
{
    int C1,C2;
    int hh=0,mm=0,ss=0;
    cin>>C1>>C2;
    
    double res;
    res=(C2-C1)/100.0;
    
    int tag=0;
    while(res>1)
    {
        ss=(ss+1)%60;
        if(ss==0)
        {
            mm=(mm+1)%60;
            if(mm==0)
                tag=1;
        }
        if(mm==0&&tag==1)
        {
            hh++;
            tag=0;
        }
        res--;
    }
    if(res>=0.5)
    {
        ss=(ss+1)%60;
        if(ss==0)
        {
            mm=(mm+1)%60;
            if(mm==0)
                tag=1;
        }
        if(mm==0&&tag==1)
        {
            hh++;
            tag=0;
        }
    }

    string asw_h,asw_m,asw_s;
    if(hh<10)
    {
        asw_h.push_back('0');
        asw_h.append(to_string(hh));
    }
    else
    {
        asw_h.append(to_string(hh));
    }
    if(mm<10)
    {
        asw_m.push_back('0');
        asw_m.append(to_string(mm));
    }
    else
    {
        asw_m.append(to_string(mm));
    }
    if(ss<10)
    {
        asw_s.push_back('0');
        asw_s.append(to_string(ss));
    }
    else
    {
        asw_s.append(to_string(ss));
    }

    cout<<asw_h<<":"<<asw_m<<":"<<asw_s<<endl;

    return 0;
}

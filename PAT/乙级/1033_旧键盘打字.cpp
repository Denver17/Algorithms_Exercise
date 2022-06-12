#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main()
{
    string broke,text;
    string asw;
    int tag=0;
    //使用getline读入string
    getline(cin,broke);
    getline(cin,text);
    asw=text;
    for(int i=0;i<broke.size();i++)
    {
        if(broke[i]=='+')
        {
            tag=1;
            break;
        }
    }
    for(int i=0;i<text.size();i++)
        for(int j=0;j<broke.size();j++)
        {
            if(tag==1)
            {
                if(text[i]>='A'&&text[i]<='Z')
                    asw[i]='*';
            }
            if(text[i]==broke[j]||
            (text[i]>='A'&&text[i]<='Z'&&text[i]+32==broke[j])||
            (text[i]>='a'&&text[i]<='z'&&text[i]-32==broke[j])
            )
            {
                asw[i]='*';
            }
        }

    asw.erase(remove(asw.begin(),asw.end(),'*'),asw.end());

    cout<<asw<<endl;
    

    return 0;
}


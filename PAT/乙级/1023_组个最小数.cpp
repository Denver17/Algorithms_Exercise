#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main()
{
    string sor[10];
    string A;

    for(int i = 0; i < 10; i++)
        cin>>sor[i];

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<atoi(sor[i].c_str());j++)
        {
            A.push_back(i+'0');
        }
    }
    //cout<<A<<endl;

    sort(A.begin(), A.end());
        for(int i=1; i<A.size(); i++)
        {
            if(A[i]>='1'&&A[i-1]=='0')
            {
                char temp;
                temp=A[i];
                A[i]=A[0];
                A[0]=temp;
                break;
            }
        }
        cout<<A<<endl;

        return 0;
}

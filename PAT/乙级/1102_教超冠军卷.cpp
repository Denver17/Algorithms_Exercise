//i_number要初始化为0
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct paper{
    string ID;
    int price;
    int number;
};


int main()
{
    int N;  cin>>N;
    if(N <= 0)  return 0;
    vector<paper> ps(N);
    int m_number = 0, m_sale = 0;
    int i_number = 0, i_sale = 0;
    for(int i = 0; i < N; i++){
        cin>>ps[i].ID>>ps[i].price>>ps[i].number;
        if(ps[i].number > m_number){
            i_number = i;
            m_number = ps[i].number;
        }
        if(ps[i].number * ps[i].price > m_sale){
            i_sale = i;
            m_sale = ps[i].number * ps[i].price;
        }
    }
    cout<<ps[i_number].ID<<" "<<ps[i_number].number<<endl;
    cout<<ps[i_sale].ID<<" "<<ps[i_sale].number * ps[i_sale].price<<endl;

    return 0;
}


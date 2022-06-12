#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    vector<string> vec;
    string str;
    while(cin>>str){
        vec.push_back(str);
    }
    reverse(vec.begin(),vec.end());
    
    cout<<vec[0];
    for(int i = 1; i < vec.size(); i++) cout<<" "<<vec[i];

    return 0;
}


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    vector<vector<vector<char> > > vec(26, vector<vector<char> >(7, vector<char>(5)));

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 7; j++){
            for(int k = 0; k < 5; k++){
                cin>>vec[i][j][k];
            }
        }
    }

    getchar();
    string str;
    getline(cin, str);
    int left = 0, right = 0;
    vector<string> asw;
    while(left < str.size()){
        while(left < str.size() && !(str[left] >= 'A' && str[left] <= 'Z')) left++;
        right = left;
        while(right < str.size() && str[right] >= 'A' && str[right] <= 'Z')   right++;
        if(left >= str.size()) break;
        
        string temp = str.substr(left, right - left);
        asw.push_back(temp);
        right++;    left = right;
    }
    
    for(int l = 0; l < asw.size(); l++){
        string temp = asw[l];
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < temp.size(); j++){
                for(int k = 0; k < 5; k++){
                    cout<<vec[(int)(temp[j] - 'A')][i][k];
                }
                if(j < temp.size() - 1)    cout<<" ";
            }
            cout<<endl;
        }
        if(l != asw.size() - 1)  cout<<endl;
    }

    return 0;
}


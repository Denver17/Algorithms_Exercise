//测试点3和4是不是有点过分了，格式对齐非常隐蔽一般考虑不到，题目却没有说明
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<stdlib.h>
using namespace std;

multimap<string,int> title_id;
multimap<string,int> author_id;
multimap<string,int> keyword_id;
multimap<string,int> publisher_id;
multimap<int,int> year_id;

void query(string str){
    cout<<str<<endl;
    char temp = str[0];
    str.erase(0,3);
    vector<int> asw;
    switch(temp){
        case '1':
        for(multimap<string,int>::iterator it = title_id.begin(); it != title_id.end(); it++){
            if(it->first == str)    asw.push_back(it->second);
        }
        break;
        case '2':
        for(multimap<string,int>::iterator it = author_id.begin(); it != author_id.end(); it++){
            if(it->first == str)    asw.push_back(it->second);
        }
        break;
        case '3':
        for(multimap<string,int>::iterator it = keyword_id.begin(); it != keyword_id.end(); it++){
            if(it->first == str)    asw.push_back(it->second);
        }
        break;
        case '4':
        for(multimap<string,int>::iterator it = publisher_id.begin(); it != publisher_id.end(); it++){
            if(it->first == str)    asw.push_back(it->second);
        }
        break;
        case '5':
        int num = atoi(str.c_str());
        for(multimap<int,int>::iterator it = year_id.begin(); it != year_id.end(); it++){
            if(it->first == num)    asw.push_back(it->second);
        }
        break;
    }
    if(asw.size() == 0) cout<<"Not Found"<<endl;
    else{
        sort(asw.begin(),asw.end());
        for(int i = 0; i < asw.size(); i++) printf("%07d\n",asw[i]);
    }
    return ;
}

int main()
{
    int N;  cin>>N;
    //vector<book> books;
    for(int i = 0; i < N; i++){
            int ID;     cin>>ID;    getchar();
            string title;   
            getline(cin,title); title_id.insert({title,ID}); 
            string author;
            getline(cin,author); author_id.insert({author,ID});
            string keywords;
            getline(cin,keywords);
            int left,right;
            for(left = 0,right = 0; right < keywords.size();){
                if(keywords[right] == ' '){
                    string str = keywords.substr(left,right-left);
                    keyword_id.insert({str,ID});
                    right++;    left = right;
                }
                else if(right == keywords.size()-1){
                    string str = keywords.substr(left,right-left+1);
                    keyword_id.insert({str,ID});
                    right++;
                }
                else    right++;
            }
            string publisher;
            getline(cin,publisher); publisher_id.insert({publisher,ID});
            int year;   
            cin>>year;  year_id.insert({year,ID});
    }

    int M;  cin>>M;
    getchar();
    for(int i = 0; i < M; i++){
        string str; getline(cin,str);
        query(str);
    }


    return 0;
}


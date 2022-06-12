#include<iostream>
#include<string>
#include<map>
using namespace std;

void week(char day)
{
    if(day=='A')
        cout<<"MON"<<" ";
    if(day=='B')
        cout<<"TUE"<<" ";
    if(day=='C')    
        cout<<"WED"<<" ";
    if(day=='D')    
        cout<<"THU"<<" ";
    if(day=='E')    
        cout<<"FRI"<<" ";
    if(day=='F')    
        cout<<"SAT"<<" ";
    if(day=='G')    
        cout<<"SUN"<<" ";
}

void hour(char hour)
{
    map<char,int> my_hour;
    my_hour.insert(map<char,int>::value_type('0',0));
    my_hour.insert(map<char,int>::value_type('1',1));
    my_hour.insert(map<char,int>::value_type('2',2));
    my_hour.insert(map<char,int>::value_type('3',3));
    my_hour.insert(map<char,int>::value_type('4',4));
    my_hour.insert(map<char,int>::value_type('5',5));
    my_hour.insert(map<char,int>::value_type('6',6));
    my_hour.insert(map<char,int>::value_type('7',7));
    my_hour.insert(map<char,int>::value_type('8',8));
    my_hour.insert(map<char,int>::value_type('9',9));
    my_hour.insert(map<char,int>::value_type('A',10));
    my_hour.insert(map<char,int>::value_type('B',11));
    my_hour.insert(map<char,int>::value_type('C',12));
    my_hour.insert(map<char,int>::value_type('D',13));
    my_hour.insert(map<char,int>::value_type('E',14));
    my_hour.insert(map<char,int>::value_type('F',15));
    my_hour.insert(map<char,int>::value_type('G',16));
    my_hour.insert(map<char,int>::value_type('H',17));
    my_hour.insert(map<char,int>::value_type('I',18));
    my_hour.insert(map<char,int>::value_type('J',19));
    my_hour.insert(map<char,int>::value_type('K',20));
    my_hour.insert(map<char,int>::value_type('L',21));
    my_hour.insert(map<char,int>::value_type('M',22));
    my_hour.insert(map<char,int>::value_type('N',23));
    if(hour<='9'&&hour>='0')
        cout<<"0"<<my_hour[hour]<<":";
    else
        cout<<my_hour[hour]<<":";
}

void judge_1(string s1,string s2)
{
    int tmp_i=0,tmp_j=0;
    int tag=0;
    for(tmp_i=0;tmp_i<s1.length()&&tmp_i<s2.length()&&tag==0;tmp_i++)
    {
        if(s1[tmp_i]==s2[tmp_i]&&
        s1[tmp_i]>=65&&s1[tmp_i]<=71)   //一个坑，判断星期字母，从A到G
        {
            week(s1[tmp_i]);
            tag=1;
        }
    }

    for(int i=tmp_i;i<s1.length()&&i<s2.length();i++)   //这里一开始tmp_i加了1，一直通不过
    {
        if(s1[i]==s2[i]&&
        ((s1[i]>=65&&s1[i]<=78)||
        (s1[i]>=48&&s1[i]<=57))         //另一个坑，判断小时字母，从0到9，从A到N
        )
        {
            hour(s1[i]);
            break;
        }
    }
}

void judge_2(string s3,string s4)
{
    int tag=0;
    for(int i=0;i<s3.length()&&i<s4.length()&&tag==0;i++)
    {
        if(s3[i]==s4[i]&&
        ((s3[i]>=65&&s3[i]<=90)||
        (s3[i]>=97&&s3[i]<=122))
        )
        {
            tag=1;
            if(i<10)
                cout<<"0"<<i;
            else
                cout<<i;
        }
    }
}


int main()
{
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    judge_1(s1,s2);
    judge_2(s3,s4);

    return 0;
}


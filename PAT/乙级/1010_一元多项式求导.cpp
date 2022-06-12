#include<iostream>
using namespace std;

#define max 10000

int main()
{
    int polynomial[max];
    int asw[max];
    int size=0,tag;

    //呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃呃
    while(cin>>polynomial[size++])
    {
        if(cin.get()=='\n')
            break;
    }

    if(polynomial[0]==0&&polynomial[1]==0)
        cout<<0<<" "<<0<<endl;
    if(polynomial[0]!=0&&polynomial[1]==0)
        cout<<0<<" "<<0<<endl;
    if(polynomial[0]==0&&polynomial[1]!=0)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }
        
    for(int i=0;i<size;i++)
    {
        asw[i]=0;
    }
    
    for(tag=0;tag<size;tag++)
    {
        if(tag%2==0)
            asw[tag]=polynomial[tag]*polynomial[tag+1]; 
        else if(tag%2==1&&polynomial[tag]!=0)
        {
            asw[tag]=polynomial[tag]-1;
        }
        else if(tag%2==1&&polynomial[tag]==0)
            continue;
    }
    for(int i=0;i<tag;i++)
    {
        if(i<tag-2)
        {
            if(i<tag-3)
                cout<<asw[i]<<" ";
            if(i==tag-3)
                cout<<asw[i];
        }
        if(i==tag-2&&asw[tag-2]==0)
            return 0;
        if(i==tag-2&&asw[tag-2]!=0)
        {
            cout<<" "<<asw[i]<<" "<<asw[i+1];
        }
    }


    return 0;
}





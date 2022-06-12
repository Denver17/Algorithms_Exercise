#include<iostream>
#include<vector>
#include<map>
using namespace std;


int main()
{
    int N;
    int asw[2][3];

    asw[0][0]=0;asw[0][1]=0;asw[0][2]=0;
    asw[1][0]=0;asw[1][1]=0;asw[1][2]=0;

    int a[3],b[3];
    a[0]=0;a[1]=0;a[2]=0;
    b[0]=0;b[1]=0;b[2]=0;

    cin>>N;
    for(int i=0;i<N;i++)
    {
        char A,B;
        cin>>A>>B;
        //平局
        if(A==B)
        {
            asw[0][1]++;
            asw[1][1]++;
        }
        //甲胜利
        else if((A=='C'&&B=='J')||(A=='J'&&B=='B')||(A=='B'&&B=='C'))
        {
            asw[0][0]++;
            asw[1][2]++;
            if(A=='B')
                a[0]++;
            else if(A=='C')
                a[1]++;
            else if(A=='J')
                a[2]++;
        }
        //乙胜利
        else if((A=='C'&&B=='B')||(A=='B'&&B=='J')||(A=='J'&&B=='C'))
        {
            asw[0][2]++;
            asw[1][0]++;
            if(B=='B')
                b[0]++;
            else if(B=='C')
                b[1]++;
            else if(B=='J')
                b[2]++;
        }
    }
    //if(asw[0][0]!=0||asw[0][2]!=0)
    //{
        cout<<asw[0][0]<<" "<<asw[0][1]<<" "<<asw[0][2]<<endl;
        cout<<asw[1][0]<<" "<<asw[1][1]<<" "<<asw[1][2]<<endl;
    //}
    int max1=-1,max2=-1;
    int tag1,tag2;
    for(int i=0;i<3;i++)
    {
        if(a[i]>max1)
        {
            max1=a[i];
            tag1=i;
        }
        if(b[i]>max2)
        {
            max2=b[i];
            tag2=i;
        }
    }
    if(tag1==0)
        cout<<"B ";
    if(tag1==1)
        cout<<"C ";
    if(tag1==2)
        cout<<"J ";
    if(tag2==0)
        cout<<"B";
    if(tag2==1)
        cout<<"C";
    if(tag2==2)
        cout<<"J";

    return 0;
}
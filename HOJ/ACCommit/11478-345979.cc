#include <iostream>
#include "string.h"
using namespace std;

char str[1000];
char strre[1000];
short lstr;
short sb[37];

void turnin()
{
    int i;lstr=strlen(str);
    for(i=0;i<36;i++)
        sb[i]=0;
    for(i=0;i<lstr;i++)
    {
        if(str[i]<=\'9\')
            strre[i]=str[i]-\'0\';
        else
            strre[i]=str[i]-87;
    }
    strre[lstr]=\'\0\';
}

void turnup()//\xd7\xaa\xbb\xd8\xa3\xac
{
    for(int i=0;i<36;i++)
        sb[i]=0;
    for(int i=0;i<lstr;i++)
    {
        if(strre[i]<10)
            strre[i]+=\'0\';
        else
            strre[i]+= 87;
    }
}

void deal()
{
    bool flag=false;
    short i,j;
    for(i=lstr-1;i>=0;i--)
    {
        for(j=strre[i]+1;j<36;j++)
            if(sb[j]>0)
            {
                flag=true;
                break;
            }
        if(flag==true)//\xc8\xe7\xb9\xfb\xd3\xd0\xc4\xc7\xbd\xcf\xb4\xf3\xb5\xc4\xbf\xd5\xb3\xf6\xc0\xb4
        {
            sb[strre[i]]++;
            sb[j]--;
            strre[i]=j;
            break;
        }
        else//\xc8\xe7\xb9\xfb\xc3\xbb\xd3\xd0\xa3\xac\xd4\xf2\xd4\xd9\xcd\xcb\xd2\xbb\xb2\xbd
        {
            sb[strre[i]]++;
        }
    }

    if(flag==false)
        cout <<str <<" -> no successor" <<endl;
    else
    {
        for(i=i+1,j=0;((i<lstr)&&(j<36));)
        {
            if(sb[j]>0)
            {
                strre[i]=j;
                sb[j]--;
                i++;
            }
            else
                j++;
        }
        turnup();
        cout <<str <<" -> " <<strre <<endl;
    }
}

int main()
{
    while(cin >>str)
    {
        turnin();
        deal();
    }
    return 0;
}


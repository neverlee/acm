#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[2][200];short len,w1,w2;
    while(cin >>str[0] >>str[1])
    {
        if(str[0][0]==\'E\')return 0;
        len=strlen(str[0]);
        w1=w2=0;
        for(int i=0;i<len;i++)
        {
            if(str[0][i]==str[1][i])continue;
            if((str[0][i]==\'R\'&&str[1][i]==\'S\')||
               (str[0][i]==\'S\'&&str[1][i]==\'P\')||
               (str[0][i]==\'P\'&&str[1][i]==\'R\'))
                w1++;
            else w2++;
        }
        cout <<"P1: " <<w1 <<endl <<"P2: " <<w2 <<endl;
    }
}
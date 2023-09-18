#include <iostream>
#include <cstring>
using namespace std;
char num1[120],num2[120];
short len;
char high;

int main()
{
    while(cin >>num1)
    {
        len=strlen(num1);
        high=0;
        for(int i=0;i<len;i++)    //\xc8\xa1\xb5\xc3\xd7\xee\xb4\xf3\xbd\xf8\xd6\xc6
            if(num1[i]>high)high=num1[i];
        char *pn2=num2+1;
        strcpy(pn2,num1);
        num1[len-1]++;
        if(high>=\'9\'&&num1[len-1]==\':\')
            num1[len-1]=\'A\';
        num2[0]=\'0\';
        num2[len]++;
        for(int i=len;i>0&&num2[i]>high;i--)
        {
             num2[i]=\'0\';num2[i-1]++;
            if(high>\'9\'&&num2[i]==(\'9\'+1))
                num2[i]=\'A\';
        }
        if(num2[0]==\'1\')pn2=num2;
        if(high==\'0\')
        {
            cout <<"1" <<endl;
            continue;
        }
        if(high==\'Z\')
        {
            cout <<pn2 <<endl;
            continue;
        }
        switch(strcmp(num1,pn2))
        {
            case -1:
                cout <<num1 <<endl <<pn2 <<endl;
                break;
            case 0:
                cout <<pn2 <<endl;
                break;    
            case 1:
                cout <<pn2 <<endl <<num1 <<endl;
                break;
        }
    }
    return 0;
}
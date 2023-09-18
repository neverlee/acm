#include <iostream>
#include "string.h"
using namespace std;

int main()
{
    char str[2001];short lstr;short k=1;
    while(1)
    {
        short left=0,right=0,all=0;
        cin >>str;
        if(str[0]==\'-\')break;
        lstr=strlen(str);
        int i,j=0;
        for(i=0;i<lstr;i++)
        {
            if(str[i]==\'{\')//\xc8\xe7\xb9\xfb\xca\xc7\xd7\xf3\xc0\xa8\xba\xc5
            {
                left++;
                for(j=(j>i?j:i+1);j<lstr;j++)
                    if(str[j]==\'}\'){all++;j++;break;}
            }
        }
        //\xca\xe4\xb3\xf6
        right=lstr-left-all;left-=all;
        all=(left>>1)+(right>>1)+((left%2)?2:0);
        cout <<k <<". " <<all <<endl;k++;
    }
    return 0;
}

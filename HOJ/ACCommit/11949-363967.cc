#include <iostream>
#include <cstring>
using namespace std;
char str[110];
int w1,w1k,w2,w2k;
int main()
{
    while(cin.getline(str,200))
    {    
        w1=w2=w1k=w2k=0;
        w2k=strlen(str);
        str[w2k]=str[0];
        for(int i=0;i<w2k;i++)
            if(str[i]==\'0\'){w2++;w1k++;}
        for(int i=0;i<w2k;i++)
            if(str[i]==\'0\'&&str[i+1]==\'0\')w1++;
        if(w2k==0){cout <<"EQUAL" <<endl;return 0;}
        w1*=w2k;w2*=w1k;
        if(w1==w2){cout <<"EQUAL" <<endl;return 0;}
        if(w1>w2){cout <<"SHOOT" <<endl;return 0;}
        if(w1<w2){cout <<"ROTATE" <<endl;return 0;}
    }
}
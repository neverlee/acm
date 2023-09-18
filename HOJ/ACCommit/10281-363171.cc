#include <iostream>
using namespace std;

char str[1000];
long num1,num2,result;
char eNum[10][8]={"zero","one","two","three","four","five","six","seven","eight","nine"};
long pi;

bool strempty(char *s1,char *s2)
{
    if(s1[0]==s2[0]&&s1[1]==s2[1])
        return 1;
    return 0;
}

void SetNum(long &num)
{
    long pj;
    num=0;
    for(;str[pi]!=0;pi++)
    {
        if(str[pi]==\'+\'||str[pi]==\'=\'){pi++;return;}
        if(str[pi]>=\'a\'&&str[pi]<=\'z\')
        {
            pj=pi;
            while(str[pj]!=\' \')pj++;
            for(int k=0;k<10;k++)
                if(strempty(eNum[k],str+pi))
                    num=num*10+k;
            pi=pj;
        }
    }
}

void PutOut()
{
    long k=1;
    while(k<result)k*=10;
    k/=10;
    while(k>0)
    {
        cout <<eNum[result/k];if(k!=1)cout <<" ";
        result-=(result/k*k);k/=10;
    }
    printf("\n");
}

int main()
{
    while(cin.getline(str,900))
    {
        if(str[0]==\'z\'&&str[7]==\'z\')return 0;
        pi=0;
        SetNum(num1);
        SetNum(num2);
        result=num1+num2;
        PutOut();
    }
    return 0;
}
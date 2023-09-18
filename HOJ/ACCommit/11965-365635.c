#include "stdio.h"
int MaxYear,MaxMonth,MaxDay;
int MinYear,MinMonth,MinDay;
int MonDay[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char ch[25];
int PrimeYear(int year)
{
    if(year%400==0 || (year%4==0 && year%100!=0) )
        return 1;
    return 0;
}
int main()
{
    int year,month,day,i,temp;
    __int64 num;
    char n,boy,girl,ok;
    MinYear=1920;
    MinMonth=1;
    MinDay=1;
    MaxYear=2009;
    MaxMonth=12;
    MaxDay=31;
    while(scanf("%s",ch)!=-1 && ch[0]!=\'e\')
    {
        year=month=day=0;
        boy=0;
        girl=0;
        ok=0;
        if(ch[0]>=\'0\' && ch[0]<=\'9\' && ch[1]>=\'0\' && ch[1]<=\'9\')
        {
            year=(ch[0]-\'0\')*10+ch[1]-\'0\';
            if(year<=9)
                year+=2000;
            else
                year+=1900;
            if(year>=MinYear && year<=MaxYear)
            {
                if(ch[2]>=\'0\' && ch[2]<=\'9\' && ch[3]>=\'0\' && ch[3]<=\'9\')
                {
                    month=(ch[2]-\'0\')*10+ch[3]-\'0\';
                    if(month>=50)
                    {
                        month-=50;
                        girl=1;
                    }
                    else
                    {
                        boy=1;
                    }
                    if(month>=1 && month<=12)
                    {
                        if(ch[4]>=\'0\' && ch[4]<=\'9\' && ch[5]>=\'0\' && ch[5]<=\'9\')
                        {
                            day=(ch[4]-\'0\')*10+ch[5]-\'0\';
                            temp=MonDay[month-1];
                            if(month==2 && PrimeYear(year))
                                temp++;
                            if(day>=1 && day<=temp)
                            {
                                num=0;
                                i=0;
                                while(0!=(n=ch[i]))
                                {
                                    if(n>=\'0\' && n<=\'9\')
                                    {
                                        n-=\'0\';
                                        num*=10;
                                        num+=n;
                                    }
                                    i++;
                                }
                                if((year<=1953 && i==10) || (year >=1954 && i==11 && num%11==0))
                                    ok=1;
                            }
                        }
                    }
                }
            }
        }
        if(ok)
        {
            if(boy)
            {
                printf("boy\n");
            }
            if(girl)
            {
                printf("girl\n");
            }
        }
        else
        {
            printf("invalid\n");
        }
    }
    return 0;
}

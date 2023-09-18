#include <cstdio>

const short MAX=20000;
bool need[10000];short start,thend;
short queue[10000];

short change[3][2]={0,1,1,2,2,3};

short GetChange(short num, short style)
{
    short a[4],t;
    a[0]=num/1000;a[1]=num%1000/100;a[2]=num%100/10;a[3]=num%10;
    if(style<4){a[style]--;if(a[style]==0)a[style]=9;goto la1;}
    if(style<8){a[style-4]++;if(a[style-4]>9)a[style-4]=1;goto la1;}
    t=a[change[style-8][0]];
    a[change[style-8][0]]=a[change[style-8][1]];
    a[change[style-8][1]]=t;
la1:return a[0]*1000+a[1]*100+a[2]*10+a[3];
}

void BFS()
{
    short low=0,high=1,step=1,shigh,k;
    for(int i=1111;i<10000;i++)need[i]=0;
    queue[0]=start;
    need[start]=1;
    while(low<high)
    {
        shigh=high;
        while(low<shigh)
        {
            for(int i=0;i<11;i++)
            {
                k=GetChange(queue[low],i);
                if(k==thend)
                {
                    printf("%ld\n",step);return;
                }
                if(!need[k])
                {need[k]=1;queue[high++]=k;}
            }
            low++;
        }
        step++;
    }
}

int main()
{
    short ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d",&start,&thend);
        if(start==thend)printf("0\n");
        BFS();
    }
    return 0;
}
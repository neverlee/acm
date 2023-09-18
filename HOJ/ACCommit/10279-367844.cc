#include<cstdio>

int first,last,pdn[6];
int main()
{
    int num;
    while(scanf("%ld",&num)!=EOF)
    {
        if(!num)return 0;
        scanf("%ld",&first);
        for(int i=0;i<6;i++)pdn[i]=first;
        while(--num)
        {
            scanf("%ld",&last);
            if(pdn[0]<0)
                for(int i=0;i<3;i++)pdn[i]=last;
            else
            {pdn[0]+=last;pdn[2]=last;}
            if(pdn[0]>pdn[3])
                for(int i=0;i<3;i++)pdn[i+3]=pdn[i];
        }
        if(pdn[3]<0)printf("0 %ld %ld\n",first,last);
        else printf("%ld %ld %ld\n",pdn[3],pdn[4],pdn[5]);
    }
}
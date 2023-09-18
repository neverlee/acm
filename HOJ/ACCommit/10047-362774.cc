#include <cstdio>
#include <cstring>

int main()
{
    int ncase;
    scanf("%d",&ncase);
    char num1[100],num2[100];
    short len1,len2;
    getchar();
    for(int text=0;text<ncase;text++)
    {
        scanf("%s %s",num1,num2);
        len1=strlen(num1);len2=strlen(num2);
        char *pn1,*pn2;
        if(len2>len1)
        {
            pn1=num2;pn2=num1;
            short t;t=len1;len1=len2;len2=t;
        }
        else
        {pn1=num1;pn2=num2;}
        for(int i=0;i<len1;i++)
            pn1[i]-=\'0\';
        for(int i=0;i<len2;i++)
            pn2[i]-=\'0\';
        for(int i=len2;i<=len1;i++)
            pn2[i]=0;
        for(int i=0;i<len1;i++)
            pn1[i]+=pn2[i];
        for(int i=0;i<len1;i++)
            if(pn1[i]>9)
            {
                pn1[i+1]+=(pn1[i]/10);
                pn1[i]%=10;
            }
        pn1[len1+1]=\'#\';
        int i=0;
        while(!pn1[i])i++;
        for(;i<len1;i++)
            printf("%d",pn1[i]);
        if(pn1[len1]==1)printf("1");
        printf("\n");
    }
    return 0;
}
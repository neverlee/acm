#include<cstdio>
#include<cstring>
char str[100010];
int len,pk;
int main()
{
    for(int text=1;gets(str);text++)
    {
        printf("Matrix %ld:\n",text);
        len=strlen(str);
        for(int n=1;;n++)
        {
            pk=n*(n+1)/2;
            if((n+1)%2)pk-=1;else pk-=n;
            if(pk<len)putchar(str[pk]);else break;
            for(int k=2;;k++)
            {
                pk=(n+k-1)*(n+k)/2;
                if((n+k)%2)pk-=k;else pk-=n;
                if(pk<len){putchar(\' \');putchar(str[pk]);}
                else break;
            }
            putchar(\'\n\');
        }
    }
    return 0;
}
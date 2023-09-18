#include <cstdio>
int main()
{
    char str[10000];
    while(gets(str))
    {
        if(str[0]==\'#\')return 0;
        for(int i=0;str[i]!=0;i++)
        {
            switch(str[i])
            {
            case \' \':printf("%%20");break;
            case \'!\':printf("%%21");break;
            case \'$\':printf("%%24");break;
            case \'%\':printf("%%25");break;
            case \'(\':printf("%%28");break;
            case \')\':printf("%%29");break;
            case \'*\':printf("%%2a");break;
            default:printf("%c",str[i]);
            }
        }
        printf("\n");
    }
}
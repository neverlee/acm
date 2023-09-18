#include <cstdio>
int main()
{
    char c;
    while(1)
    {
        c=getchar();
        if(c==\'#\')return 0;
        switch(c)
        {
        case \' \':printf("%%20");break;
        case \'!\':printf("%%21");break;
        case \'$\':printf("%%24");break;
        case \'%\':printf("%%25");break;
        case \'(\':printf("%%28");break;
        case \')\':printf("%%29");break;
        case \'*\':printf("%%2a");break;
        default:printf("%c",c);
        }
    }
}
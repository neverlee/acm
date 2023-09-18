#include <cstdio>

int main()
{
    int ncase;
    scanf("%ld",&ncase);
    int num;char str[100];
    for(int text=0;text<ncase;text++)
    {
        scanf("%d %s",&num,str);
        printf("%d ",text+1);
        int i;
        for(i=0;str[i];i++)
            if(i!=num-1)
                putchar(str[i]);
        printf("\n");
    }
    return 0;
}
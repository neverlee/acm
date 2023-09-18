#include <cstdio>

int main()
{
    int num;
    while(scanf("%ld",&num))
    {
        if(num==0)return 0;
        if(num<=8){printf("no solution\n");continue;}
        for(int i=0;i<num;i++)
            putchar(\'1\');
        putchar(\'\n\');
    }
}
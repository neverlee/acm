#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    {
        bool space = 0;
        for(int i=1;i<=n;i++)
        {
            if(space)printf(" ");
            if(i%3!=0&&i%5!=0)
            {
                printf("%d",i);space=1;
            }
            else
            {
                if(i%3==0&&i%5!=0)
                    printf("Dead");
                if(i%3!=0&&i%5==0)
                    printf("Man");
                if(i%3==0&&i%5==0)
                    printf("DeadMan");
                printf("\n");space=0;
            }
        }
    }
    return 0;
}
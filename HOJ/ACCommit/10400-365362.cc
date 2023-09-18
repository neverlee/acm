#include <cstdio>
int main()
{
    int ncase,x,y;
    scanf("%ld",&ncase);
    for(int text=0;text<ncase;text++)
    {
        scanf("%d%d",&x,&y);
        if(x>=y)
            printf("MMM BRAINS\n");
        else
            printf("NO BRAINS\n");
    }
    return 0;
}
#include<cstdio>
const int msq=14400;
int t,w;
int main()
{
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&w);
        if(w>120)w=120;
        printf("%.3lf\n",(msq-(120-w)*(120-w))/(2.0*msq));
    }
    return 0;
}
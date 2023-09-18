#include <cstdio>
const double PI = 3.14159265354;
int main()
{
    int ncase,angle;
    scanf("%ld",&ncase);
    while(ncase--)
    {
        scanf("%ld",&angle);
        printf("%.3lf\n",(double)angle/180.0*PI);
    }
    return 0;
}
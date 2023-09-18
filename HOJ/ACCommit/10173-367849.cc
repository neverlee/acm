#include<cstdio>
#include<cmath>
double r,t,p;
int main()
{
    while(scanf("%lf%lf%lf",&r,&t,&p)!=EOF)
        printf("(%.2lf,%.2lf,%.2lf)\n",r*sin(t)*cos(p),r*sin(t)*sin(p),r*cos(t));
    return 0;
}
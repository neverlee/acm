#include <cstdio>

int main()
{
    int ncase;
    scanf("%ld",&ncase);
    double x,y,k;double z;
    for(int text=0;text<ncase;text++)
    {
        scanf("%lf%lf%lf",&x,&y,&z);
        if(x>y){
            k=x;x=y;y=k;
        }
        if(60*(y-x)-z<=1e-7)
            printf("1.0000000\n");
        else{
            k=60*(y-x);
            printf("%.7lf\n",1-(k-z)*(k-z)/(k*k) );
        }
    }
    return 0;
}
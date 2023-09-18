#include "stdio.h"
#include "math.h"
#define PI 3.14159265354

int main()
{
    int ncase,One[2],Two[2],Size;
    double L,R,OneSize,TwoSize,ThreeSize,FourSize,Lon;
    L=40000.00;
    //R=L/2/PI;
    R=1;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d%d%d",&One[0],&One[1],&Two[0],&Two[1]);
        OneSize=R*cos(One[1]/180.0*PI);
        TwoSize=R*cos(Two[1]/180.0*PI);
        Size=One[0]-Two[0];
        if(Size<0)
            Size=-Size;
        if(Size>180)
            Size=360-Size;
        ThreeSize=OneSize*OneSize+TwoSize*TwoSize-2*OneSize*TwoSize*cos(Size/180.0*PI);
        OneSize=R*sin(One[1]/180.0*PI);
        TwoSize=R*sin(Two[1]/180.0*PI);
        FourSize=(OneSize-TwoSize)*(OneSize-TwoSize);
        Lon=FourSize+ThreeSize;
        Lon=sqrt(Lon);
        Lon/=2;
        Lon=asin(Lon)/(PI);
        Lon*=L;
        printf("%.3lf\n",Lon);
    }
    return 0;
}
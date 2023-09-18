#include <stdio.h>
#include <math.h>

#define PI 3.141592653589

int main()
{
    int t;
    double x1,y1,r1,x2,y2,r2,P;
    double Result,H;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2,&P);
        H = sqrt(((x1 - x2) * (x1 - x2)) + ((y1- y2) * (y1 - y2)));
        if (H >= r1 + r2)
            Result = PI * r1 * r1 + PI * r2 * r2;
        else if(H <= fabs(r1 - r2))
        {
            if (r1 > r2)
                Result = r1 * r1 * PI;
            else
                Result = r2 * r2 * PI;
        }
        else
        {
            double a1,a2,R11,R22;
            a1 = acos((r1 * r1 + H * H - r2 * r2) /(2 * r1 * H));
            if (a1 > PI / 2)
                R11 = r1 * r1 * PI - ((r1 * r1 * a1) + (r1 * sin(a1)) * (r1 * cos(PI - a1)));
            else
                R11 = r1 * r1 * PI - ((r1 * r1 * a1) - (r1 * sin(a1)) * (r1 * cos(a1)));

            a2 = acos((r2 * r2 + H * H - r1 * r1) /(2 * r2 * H));
            if (a2 > PI / 2)
                R22 = r2 * r2 * PI - ((r2 * r2 * a2) + (r2 * sin(a2)) * (r2 * cos(PI - a2)));
            else
                R22 = r2 * r2 * PI - ((r2 * r2 * a2) - (r2 * sin(a2)) * (r2 * cos(a2)));

            Result = R11 + R22;
        }
        printf("%.2lf\n",Result * P);
    }

    return 0;
}

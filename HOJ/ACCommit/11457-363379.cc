#include <iostream>
using namespace std;
double temp,s;
int main()
{
    int ncase;
    cin >>ncase;
    for(int text=0;text<ncase;text++)
    {
        cin >>s;
        if(s<=500)
        {
            temp=1500*(1000+s)/7000;
            printf("%.3lf\n",temp*2200/1500);
        }
        else if(s<=1900)
        {
            temp=(2500+s)/2;
            temp=temp*temp/7000;
            printf("%.3lf\n",temp*2200/1500);
        }
        else if(s<=7300)
        {
            s=(4700+s)/3;
            temp=s*s/7000;
            printf("%.3lf\n",temp*s/1500);
        }
        else
        {
            s=(s-7300)/2;
            temp=2*(4000.0+s)*(4000.0+s);
            printf("%.3lf\n",temp/5250);
        }
    }
    return 0;
}
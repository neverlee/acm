#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    const double c1=0.798179868358, c2=0.434294481903;
    double c3;
    while(cin >>n)
    {
        if(n<=3){cout <<1 <<endl;continue;}
        c3=log10(n);
        n=(int)((c3+c1)/2+n*(c3-c2)+1);
        cout <<n <<endl;
    }
    return 0;
}
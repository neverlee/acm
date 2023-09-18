#include <iostream>
using namespace std;
int main()
{
    int ncase,mi,ma,tn,num;cin >>ncase;
    while(ncase--)
    {
        cin >>num;
        mi=9999;ma=-1;
        for(int i=0;i<num;i++)
        {
            cin >>tn;
            if(tn>ma)ma=tn;
            if(tn<mi)mi=tn;
        }
        cout <<2*(ma-mi) <<endl;
    }
    return 0;
}
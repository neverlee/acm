#include <iostream>
using namespace std;
const long Max=1000000L;
short Aexp,Bexp;
long A,B;
int main()
{
    short kcase=1;
    while(1)
    {
        long dn=0,dist=0;
        cin >>A >>B;
        if(A==0)break;
        if((A%2==0)||(B%2==0))
        {
            Aexp=Bexp=0;
            while(A%2==0){A/=2;Aexp++;}
            while(B%2==0){B/=2;Bexp++;}
            dist+=Aexp>Bexp?Aexp-Bexp:Bexp-Aexp;
            dn++;
        }
        for(long i=3L;i<Max;i+=2)
        {
            if((A%i==0)||(B%i==0))
            {
                Aexp=Bexp=0;
                while(A%i==0){A/=i;Aexp++;}
                while(B%i==0){B/=i;Bexp++;}
                dist+=Aexp>Bexp?Aexp-Bexp:Bexp-Aexp;
                dn++;
            }
        }
        cout <<kcase <<". " <<dn <<":" <<dist <<endl;
        kcase++;
    }
    return 0;
}
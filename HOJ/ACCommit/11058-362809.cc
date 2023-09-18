#include <iostream>
using namespace std;
inline long sf(long a,long b)
{
    long k=1;
    for(int i=0;i<b;i++)
        k*=a;
    return k;
}

int main()
{
    long a,b,k,i,t1,t2;
    while(cin >>a >>b)
    {
        if(!a)return 0;
        i=1;
        while((t1=sf(i,b))<a)i++;
        t2=sf(i-1,b);
        if(t1-a>a-t2)
            cout <<i-1 <<endl;
        else
            cout <<i <<endl;
    }
}
#include <stdio.h>
unsigned long m;
unsigned long aff(unsigned long a,unsigned long b)
{
    if(b!=0)
    {
        int k=aff(a,b/2);
        if(b%2==0)
            return (k*k)%m;
        else
            return ((k*k)%m*a)%m;
    }
    else return 1;
}
int main()
{
   unsigned long n,a,b,add=0;
   scanf("%lu%lu",&m,&n);
   while(n--)
   {
       scanf("%lu%lu",&a,&b);
       add+=aff(a%m,b)%m;
       add%=m;
   }
   printf("%lu",add);
   return 0;
}

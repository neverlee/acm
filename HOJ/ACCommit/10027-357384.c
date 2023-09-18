#include "stdio.h"
const long SIZE=50001;
int main()
{
    long num,i,j,stack[SIZE],pt=0,temp,low,high,mid;
    stack[0]=-1;
    scanf("%ld",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&temp);
        if(temp>stack[pt]){pt++;stack[pt]=temp;}
        else
        {
            low=0,high=pt;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(temp>stack[mid])low=mid+1;
                else high=mid-1;
            }
            stack[low]=temp;
        }
    }
    printf("%ld\n",pt);
    return 0;
}
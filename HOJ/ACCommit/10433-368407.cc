#include<stdio.h>
short bit[8]={128,64,32,16,8,4,2,1};
int ele,have,num,i;
bool ta,tb;

int main()
{
    scanf("%d",&num);
    scanf("%d",&ele);
    ta=(bit[0]&ele);have=1;
    for(i=1;i<num;i++)
    {
        if(i%8==0)scanf("%d",&ele);
        tb=bit[i%8]&ele;
        if(ta==tb)++have;
        else//\xb7\xf1\xd4\xf2
        {
            printf("%d ",have|(ta?bit[0]:0));
            have=1;ta=tb;
        }
    }
    printf("%d ",have|(ta?bit[0]:0));
    return 0;
}
#include<stdio.h>
#include<iostream>
short bit[8]={128,64,32,16,8,4,2,1};
int ele,have,num,i;
bool ta,tb;

int main()
{
    scanf("%d",&num);
    scanf("%d",&ele);//\xb5\xda\xd2\xbb\xb8\xf6\xca\xfd
    ta=(bit[0]&ele);have=1;//\xb5\xda\xd2\xbb\xce\xbb
    for(i=1;i<num;i++)
    {
        if(i%8==0)scanf("%d",&ele);//\xb5\xb1
        tb=bit[i%8]&ele;
        if(ta==tb)++have;//\xb5\xb1\xcf\xc2\xd2\xbb\xce\xbb\xcf\xe0\xcd\xac\xa3\xac
        else//\xb7\xf1\xd4\xf2
        {
            printf("%d ",have|(ta?bit[0]:0));
            have=1;ta=tb;
        }
    }
    printf("%d ",have|(ta?bit[0]:0));//\xca\xe4\xb3\xf6\xd7\xee\xba\xf3\xd2\xbb\xcf\xee
    return 0;
}
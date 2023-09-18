#include <cstdio>

unsigned base[4]={2,3,5,7};
unsigned humble[5900]={1,2,3,4,5,6,7,8,9,10,12,14,15,16,18,20,21,24,25,27};
unsigned small,low,high,mid,fend;

void SetHumble()
{
    for(unsigned i=20;i<5842;i++)
    {
        small=1<<31;
        for(unsigned j=0;j<4;j++)
        {
            fend=humble[i-1]/base[j];
            low=0;high=i-1;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(fend>humble[mid])low=mid+1;
                else high=mid-1;
            }
            while(humble[low]<=fend)low++;
            fend=humble[low]*base[j];
            if(small>fend)small=fend;
        }
        humble[i]=small;
    }
}

int main()
{
    unsigned num;
    SetHumble();
    while(scanf("%ld",&num),num)
    {
        printf("The %ld",num);
        if(num%10==1&&num%100!=11)printf("st");
        else if(num%10==2&&num%100!=12)printf("nd");
        else if(num%10==3&&num%100!=13)printf("rd");
        else printf("th");
        printf(" humble number is %lu.\n",humble[num-1]);
    }
    return 0;
}
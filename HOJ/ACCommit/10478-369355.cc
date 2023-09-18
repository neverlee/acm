#include<cstdio>

const int SIZE = 100010;
int ele[SIZE],left[SIZE],right[SIZE],num;

void Result()
{
    int amax,mmax;
    right[num-1]=ele[num-1];
    for(int i=num-2;i>=0;i--)
        right[i]=right[i+1]<0?ele[i]:right[i+1]+ele[i];
    amax=left[0]=ele[0];
    mmax=amax+right[1];
    for(int i=1;i<num-1;i++)
    {
        left[i]=left[i-1]<0?ele[i]:left[i-1]+ele[i];
        amax=amax>left[i]?amax:left[i];
        mmax=mmax>amax+right[i+1]?mmax:amax+right[i+1];
    }
    printf("%ld\n",mmax);
}

int main()
{
    while(scanf("%ld",&num))
    {
        if(!num)return 0;
        for(int i=0;i<num;i++)
            scanf("%ld",ele+i);
        Result();
    }
}
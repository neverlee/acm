#include <cstdio>

long long px[10010],py[10010],num,result;
int ncase;

void QuickSort(long long *data, int low, int high)
{
    if(low<high)
    {
        int i(low),j(high);
        long long temp=data[i];
        do{
            while((data[j]>=temp)&&(i<j))j--;
            if(i<j)data[i++]=data[j];
            while((data[i]<=temp)&&i<j)i++;
            if(i<j)data[j--]=data[i];
        }while(i<j);
        data[i]=temp;
        QuickSort(data,low,i-1);
        QuickSort(data,i+1,high);
    }
}

inline long long as(long long x)
{return x<0?-x:x;}

int main()
{
    scanf("%d",&ncase);
    for(int text=1;text<=ncase;text++)
    {
        scanf("%d",&num);
        for(int i=0;i<num;i++)
            scanf("%I64d%I64d",px+i,py+i);
        QuickSort(px,0,num-1);
        QuickSort(py,0,num-1);
        result=0;
        for(int i=1,j=num-1;i<num;i++,j--)
            result+=(px[i]-px[i-1]+py[i]-py[i-1])*i*j;
        printf("Case #%d: %I64d\n",text,result);
    }
    return 0;
}
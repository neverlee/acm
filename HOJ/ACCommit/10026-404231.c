#include <stdio.h>
#include <malloc.h>
typedef struct student {
    char name[20];
    int  average;
    int lastgrade;
    char ganbu;
    char giguan;
    int  thesis;
    int reward;
    int con;
}stu;
void fun(stu a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i].average>80&&a[i].thesis>=1)
            a[i].reward+=8000;
        if(a[i].average>85&&a[i].lastgrade>80)
            a[i].reward+=4000;
        if(a[i].average>90)
            a[i].reward+=2000;
        if(a[i].average>85&&a[i].giguan==\'Y\')
            a[i].reward+=1000;
        if(a[i].lastgrade>80&&a[i].ganbu==\'Y\')
            a[i].reward+=850;
    }
}
void sort(stu a[],int n)
{
    int j,i;
    for(i=n-1;i>0;i--)
        for(j=i-1;j>=0;j--)
        {
            if(a[j].reward>=a[i].reward)
                a[i].con++;
            else a[j].con++;
        }
}
int  findmax(stu a[],int n)
{
    int j,max=0;
    for(j=1;j<n;j++)
        if(a[j].con<a[max].con)
                max=j;
    return max;
}
int main()
{
    int n,i,t,sum=0;
    scanf("%d",&n);
    stu *p=(stu *)malloc(sizeof(stu)*n);
    for(i=0;i<n;i++)
    {
        scanf("%s %d %d %c %c %d",
        p[i].name,&p[i].average,&p[i].lastgrade,
        &p[i].ganbu,&p[i].giguan,&p[i].thesis);
        p[i].reward=0;
        p[i].con=0;
    }
    fun(p,n);
    sort(p,n);
    t=findmax(p,n);
    for(i=0;i<n;i++)
        sum+=p[i].reward;
    printf("%s\n%d\n%d\n",p[t].name,p[t].reward,sum);
    return 0;
}
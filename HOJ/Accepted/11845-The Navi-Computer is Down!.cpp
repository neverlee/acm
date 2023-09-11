// 11845-The Navi-Computer is Down!.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "stdio.h"

long long n2(long long x)
{return x*x;}

long long getnum()
{
	long long t1,t2;
	scanf("%I64d.%I64d",&t1,&t2);
	return t1*100+t2;
}

int main()
{
	char name1[40],name2[40];
	long long x1,y1,z1,x2,y2,z2,re2,low,high,mid;
	int n,i;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		gets(name1);
		x1=getnum();y1=getnum();z1=getnum();
		getchar();
		gets(name2);
		x2=getnum();y2=getnum();z2=getnum();
		getchar();
		high=re2=n2(x1-x2)+n2(y1-y2)+n2(z1-z2);
		low=0;high=40000000;
		while(low<high)
		{
			mid=(low+high)/2;
			if(n2(mid)<re2)
				low=mid+1;
			else
				high=mid-1;
		}
		high=low-1;
		if(((n2(high)+high)*100+25)>(re2*100))low--;
		printf("%s to %s: %I64d.%02I64d\n",name1,name2,
			low/100,low%100);
	}
	return 0;
}


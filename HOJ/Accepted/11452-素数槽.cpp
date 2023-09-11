// 11452-素数槽.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

long prime[100000]={2,3};

void InitPrime()
{
	long k=2;
	for(long i=5;i<=1299709;i+=2)
	{
		bool flag=1;
		for(long j=0;prime[j]<=(long)sqrt((double)i);j++)
			if(!(i%prime[j]))
			{flag=0;break;}
		if(flag){prime[k]=i;k++;}
	}
}


int main()
{
	long num,low,high,mid;
	InitPrime();
	short ncase;
	cin >>ncase;
	for(int i=0;i<ncase;i++)
	{
		cin >>num;
		low=0;high=99999;
		while(low<high)
		{
			mid=(low+high)>>1;
			if(num>prime[mid])
				low=mid+1;
			else
				high=mid-1;
		}
		while(prime[low]<num)++low;
		if(prime[low]==num||prime[low-1]==num)cout <<0 <<endl;
		else
			cout <<prime[low]-prime[low-1] <<endl;
	}
	return 0;
}
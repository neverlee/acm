// 10282-The produce of combination.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>

class CountNumber
{
	private:
		short num[30],total,max;
	public:
		void Work();
		void SetNumber(int n,int m);
		void Combination();
};

void CountNumber::SetNumber(int n,int themax)
{max=themax;total=n;}


void CountNumber::Work()
{
	printf("%ld",num[0]);
	for(int i=1;i<total;i++)
		printf(" %d",num[i]);
	printf("\n");
}
void CountNumber::Combination()
{
	for(int i=0;i<=total;i++)num[i]=i;
	int lv=0;
	while(lv>=0)
	{
		if(lv==total)
			Work();
		if(num[lv]<=max-total+lv&&lv<total)
		{
			num[lv++]++;num[lv]=num[lv-1];
		}
		else
		{
			num[lv]=num[lv-1];lv--;
		}
	}
}
int main()
{
	int n,k,ncase;CountNumber cn;
	scanf("%ld",&ncase);
	for(int i=1;i<=ncase;i++)
	{
		scanf("%ld%ld",&n,&k);
		cn.SetNumber(k,n);
		printf("Case %ld:\n",i);
		cn.Combination();
	}
	return 0;
}

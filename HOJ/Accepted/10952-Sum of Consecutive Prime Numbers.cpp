// 10952-Sum of Consecutive Prime Numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <cstdio>
#include <cmath>

class Prime
{
	public:
		int num,*prime;
		Prime(int max,int n);
		~Prime();
};
Prime::Prime(int max,int n)
{
	prime=new int[n];
	int m;
	bool isPrime;
	prime[0]=2;prime[1]=3;prime[2]=5;
	num=3;
	for(int i=7;i<=max;i+=2)
	{
		isPrime=1;m=(int)sqrt((double)i);
		for(int j=0;prime[j]<=m;j++)
			if(i%prime[j]==0)
			{isPrime=0;break;}
		if(isPrime)
			prime[num++]=i;
	}
}
Prime::~Prime()
{delete [] prime;}

Prime thep(10000,1300);

int add[1300],result[10001];

void SetResult()
{
	add[0]=0;
	for(int i=1;i<=thep.num;i++)
		add[i]=add[i-1]+thep.prime[i-1];
	for(int i=0;i<10001;i++)result[i]=0;
	for(int i=0;i<thep.num;i++)
		for(int j=i+1;j<thep.num&&add[j]-add[i]<10001;j++)
			++result[add[j]-add[i]];
}
int main()
{
	int in;
	SetResult();
	while(scanf("%ld",&in),in)
	{
		printf("%ld\n",result[in]);
	}
	return 0;
}


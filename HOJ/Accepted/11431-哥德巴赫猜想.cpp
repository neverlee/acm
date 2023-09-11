// 11431-哥德巴赫猜想.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
const long SIZE=16777217;
bool isPrime[SIZE]={1,1,0};

void SetPrime()
{
	int k;
	for(int i=3;i<4096;i+=2)
		if(!isPrime[i])
			for(int j=i;(k=i*j)<SIZE;j+=2)
				isPrime[k]=1;
}

int main()
{
	SetPrime();
	int num,total;
	while(scanf("%ld",&num)!=EOF)
	{
		total=0;
		for(int i=3;i<=num-i;i+=2)
			if(!isPrime[i]&&!isPrime[num-i])total++;
		printf("%ld\n",total);
	}
	return 0;
}
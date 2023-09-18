// 10714-Sum of Different Primes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cmath>
using namespace std;

short prime[200]={2,3,5},total;
long result[15][1121];
void InitPrime()
{
	bool flag;total=3;
	for(short i=7;i<1120;i+=2)
	{
		flag=1;
		for(int j=0;prime[j]<=(short)sqrt((double)i);j++)
			if(i%prime[j]==0)
			{flag=0;break;}
		if(flag){prime[total]=i;++total;}
	}
}

void SetResult()
{
	for(int i=0;i<15;i++)
		for(int j=0;j<1120;j++)
			result[i][j]=0;
	result[0][0]=1;
	for(int i=0;i<total;i++)
		for(int j=13;j>=0;j--)
			for(int k=0;k<1121;k++)
			{
				if(k+prime[i]>1120)break;
				result[j+1][k+prime[i]]+=result[j][k];
			}
}

int main()
{
	InitPrime();
	SetResult();
	int ni,ki;
	while(cin >>ni >>ki)
	{
		if(ni==0)return 0;
		cout <<result[ki][ni] <<endl;
	}
}
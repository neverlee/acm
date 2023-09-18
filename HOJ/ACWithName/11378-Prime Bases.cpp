// 11378-Prime Bases.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <iostream>
using namespace std;
long prime[20]={1,2,3,5,7,11,13,17,19,23,29};
long long base[20]={1},num;

void InitBase()
{
	for(int i=1;i<11;i++)
		base[i]=base[i-1]*prime[i];
}

inline void PutK(int k)
{
	for(int i=1;i<=k;i++)
		printf("*%ld",prime[i]);
}
void GetResult()
{
	printf("%I64d = ",num);
	long lastBase[20]={0},wei=0;
	while(num>=base[wei])wei++;
	wei;
	for(int i=wei-1;num>0;i--)
	{
		lastBase[i]=num/base[i];
		num%=base[i];
	}

	if(lastBase[0])printf("1 + ");
	int i=1;
	while(!lastBase[i]&&i<wei)i++;
	printf("%ld",lastBase[i]);PutK(i);
	for(i=i+1;i<wei;i++)
	{
		if(lastBase[i])
		{
			printf(" + %ld",lastBase[i]);
			PutK(i);
		}
	}
	printf("\n");
}

int main()
{
	InitBase();
	while(scanf("%I64d",&num),1)
	{
		if(!num)return 0;
		if(num==1){printf("1 = 1\n");continue;}
		GetResult();
	}
}
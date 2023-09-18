// 10149-Bit Strings.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
int num;
int bit[15];

bool IsGood()
{
	int total=0;
	for(int i=1;i<num;i++)
		if(bit[i]==1&&bit[i+1]==1)
			total++;
	if(total==1)return 1;
	return 0;
}

void SetBit()
{
	for(int i=0;i<=num;i++)bit[i]=-1;
	int level=1;
	while(level>0)
	{
		if(level>num)
		{
			if(IsGood())
			{
				for(int i=1;i<=num;i++)
					printf("%d",bit[i]);
				printf("\n");
			}
		}
		else if(bit[level]<1)
		{
			bit[level]++;level++;continue;
		}
		bit[level]=-1;level--;
	}
}

int main()
{
	while(scanf("%d",&num)!=EOF)
		SetBit();
	return 0;
}
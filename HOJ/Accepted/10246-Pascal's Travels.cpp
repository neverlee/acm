// 10246-Pascal's Travels.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdio>

char rect[40][40];
long long res[40][40];
int num;

int main()
{
	while(scanf("%ld",&num)!=EOF)
	{
		if(num==-1)return 0;
		getchar();
		for(int i=0;i<num;i++)gets(rect[i]);
		for(int i=0;i<num;i++)
			for(int j=0;j<num;j++)
			{res[i][j]=0LL;rect[i][j]-='0';}
		res[0][0]=1LL;rect[num-1][num-1]='9';
		for(int i=0;i<num;i++)
			for(int j=0;j<num;j++)
			{
				if(i+rect[i][j]<num)
					res[i+rect[i][j]][j]+=res[i][j];
				if(j+rect[i][j]<num)
					res[i][j+rect[i][j]]+=res[i][j];
			}
		printf("%I64d\n",res[num-1][num-1]);
	}
}
// 11954-Bags.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>

int inNum[1001][101];

void SetInNum()
{
	inNum[1][1]=2;inNum[0][0]=1;
	for(int i=1;i<=1000;i++)
	{
		inNum[i][0]=1;inNum[i][1]=i+1;
	}
	for(int i=2;i<=1000;i++)
		for(int j=1;j<=100;j++)
		{
			if(i==j){inNum[i][j]=inNum[i][j-1]*2;break;}
			inNum[i][j]=inNum[i-1][j]+inNum[i][j-1];
		}
}

inline int GetInNum(int n,int k)
{
	if(n>=k)return inNum[n][k];
	else return inNum[k][n];
}

double GetResult(int &my,int &total)
{
	if(my==0)return 0.0;
	double alltime=my,div=1;int temp;
	for(int i=my+1;i<=total;i++)
	{
		temp=GetInNum(my-1,i-my);
		div+=temp;
		alltime+=temp*i;
	}
	printf("%lf,%lf\n",alltime,div);
	return (double)alltime/(double)div;
}

int main()
{
	int ncase;
	scanf("%d",&ncase);int my,total;
	SetInNum();
	for(int text=0;text<ncase;text++)
	{
		scanf("%d%d",&my,&total);
		printf("%.6lf\n",GetResult(my,total));
	}
	return 0;
}

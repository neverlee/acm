// 10009-Game of Connections.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;
short result[101][250];
void Init()
{
	for(int i=0;i<101;i++)
		for(int j=0;j<250;j++)
			result[i][j]=0;
}

void SetResult()
{
	result[1][0]=result[1][1]=1;
	for(int i=2;i<=100;i++)
	{
		result[i][0]=result[i-1][0];
		for(int j=1;j<=result[i][0];j++)
			result[i][j]=result[i-1][j]*(4*i-2);
		short kw;
		for(kw=1;kw<result[i][0];kw++)
		{
			result[i][kw+1]+=(result[i][kw]/10);
			result[i][kw]%=10;
		}
		while(result[i][kw]>9)
		{
			result[i][kw+1]=result[i][kw]/10;
			result[i][kw]%=10;
			result[i][0]++;
		}
		for(int j=result[i][0];j>0;j--)
		{
			result[i][j-1]+=((result[i][j]%(i+1))*10);
			result[i][j]/=(i+1);
		}
		while(!result[i][result[i][0]])result[i][0]--;
	}
}

void PutOut(short i)
{
	for(int kw=result[i][0];kw>0;kw--)
		cout <<result[i][kw];
	cout <<endl;
}
int main()
{
	short num;
	Init();
	SetResult();
	while(cin >>num)
	{
		if(num==-1)return 0;
		PutOut(num);
	}
}
// 11938-Adjacent Bit Counts.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

unsigned long long fn[101][100];

void Init()
{
	for(int i=0;i<101;i++)
		for(int j=0;j<100;j++)fn[i][j]=0;
	for(int i=3;i<101;i++){fn[i][i-1]=1;fn[i][i-2]=2;}
	fn[1][0]=2;fn[2][0]=3;fn[2][1]=1;fn[3][0]=5;
	for(int i=4;i<=100;i++)
		for(int j=0;j<i-2;j++)
		{
			fn[i][j]=fn[i-1][j]+fn[i-2][j];
			for(int m=i-3,n=j-1;m>0&&n>=0;m--,n--)
				fn[i][j]+=fn[m][n];
		}
}
int main()
{
	Init();
	int ncase;cin >>ncase;
	int num,pk;
	for(int text=1;text<=ncase;text++)
	{
		cin >>num >>num >>pk;
		cout <<text <<" " <<fn[num][pk] <<endl;
	}
	return 0;
}

// 10010-Recaman's Sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
bool isHave[30000000]={0};
long num[500001]={0,1};

int main()
{
	isHave[0]=isHave[1]=1;
	for(int i=2;i<=500000;i++)
	{
		num[i]=num[i-1]-i;
		if(num[i]<0||isHave[num[i]])
		{num[i]=num[i-1]+i;}
		isHave[num[i]]=1;
	}
	long n;
	while(cin >>n)
	{
		if(n==-1)return 0;
		cout <<num[n] <<endl;
	}
}
// 11759-Least Common Multiple.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cmath>
using namespace std;
short prime[10000]={2,3,5},nump=3;
void InitPrime()
{
	bool flag;
	for(int i=7;i<10000;i+=2)
	{
		flag=1;
		for(int j=0;prime[j]<=(short)sqrt((float)i);j++)
			if(i%prime[j]==0){flag=0;break;}
		if(flag)prime[nump]=i;nump++;
	}
	cout <<nump <<endl;
}

int main()
{
	//InitPrime();
	return 0;
}


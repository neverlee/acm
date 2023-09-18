// 10476-Sequence Sum Possibilities.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<iostream>
#include<cmath>
using namespace std;
unsigned ncase,num,mx,total;

int main()
{
	cin >>ncase;
	for(int text=1;text<=ncase;text++)
	{
		cin >>num >>num;
		num*=2;
		total=0;
		mx=(unsigned)sqrt((double)num);
		for(unsigned k=2;k<=mx;k++)
			if(num%k==0&&(num/k+1-k)%2==0&&num/k+1-k>0)
				++total;
		cout <<text <<" " <<total <<endl;
	}
	return 0;
}


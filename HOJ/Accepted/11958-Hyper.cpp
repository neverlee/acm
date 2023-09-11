// 11958-Hyper.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int result[220];
int main()
{
	int ncase;cin >>ncase;int num,a,b;
	for(int text=0;text<ncase;text++)
	{
		for(int i=0;i<220;i++)result[i]=0;
		cin >>num;
		for(int i=0;i<num;i++)
		{
			cin >>a >>b;
			for(int j=a;j<=a+b-1;j++)
				result[j]++;
		}
		int max=0;
		for(int i=0;i<220;i++)
			if(result[i]>max)max=result[i];
		cout <<max <<endl;
	}
	return 0;
}
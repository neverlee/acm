// 11885-Help Chelsea!.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int ncase;
	cin >>ncase;
	for(int i=0;i<ncase;i++)
	{
		int number;cin >>number;
		long tn,max=0;char name[30],ts[30];
		for(int j=0;j<number;j++)
		{
			cin >>tn >>ts;char *p=ts;
			while(*(p+0)==' ')p++;
			if(tn>max)
			{
				max=tn;strcpy(name,p);
			}
		}
		cout <<name <<endl;
	}
	return 0;	
}
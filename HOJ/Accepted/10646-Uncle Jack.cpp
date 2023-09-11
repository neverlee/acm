// 10646-Uncle Jack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
using namespace std;

int main()
{
	int naphew, cds, num[27],wei;
	while(cin >>naphew >>cds)
	{
		if(naphew==0)return 0;
		if(cds==0){cout <<1 <<endl;continue;}
		for(int i=1;i<27;i++)
			num[i]=0;
		num[0]=1;wei=1;
		for(int i=0;i<cds;i++)
		{
			for(int j=0;j<wei;j++)
				num[j]*=naphew;
			for(int j=0;j<wei;j++)
			{num[j+1]+=num[j]/10;num[j]%=10;}
			if(num[wei]>0)wei++;
		}
		for(int i=wei-1;i>=0;i--)
			cout <<num[i];
		cout <<endl;
	}
}


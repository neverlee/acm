// 10017-Exact Change Only.cpp : 定义控制台应用程序的入口点。
// 10838-Exact Change Only

#include "stdafx.h"


#include <iostream>
using namespace std;
int a[4],re[4],minx,ihave;
double money;

void GetResult()
{
	bool ishave=0;
	minx=9999;
	for(int i=0;i<=a[0];i++)
		for(int j=0;j<=a[1];j++)
			for(int k=0;k<=a[2];k++)
				for(int m=0;m<=a[3];m++)
				{
					if(i*25+j*10+k*5+m==ihave&&i+j+k+m<minx)
					{
						minx=i+j+k+m;
						re[0]=i;re[1]=j;re[2]=k;re[3]=m;
						ishave=1;
					}
				}
	if(ishave)
		cout <<re[0]<<" "<<re[1]<<" "<<re[2]<<" "<<re[3]<<endl;
	else
		cout <<"NO EXACT CHANGE"<<endl;
}

int main()
{
	while(cin >>money)
	{
		for(int i=0;i<4;i++)cin >>a[i];
		ihave=(int)(money*100+0.1);
		GetResult();
	}
	return 0;
}
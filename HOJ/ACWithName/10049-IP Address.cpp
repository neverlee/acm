// 10049-IP Address.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	short num;
	cin >>num;
	for(int i=0;i<num;i++)
	{
		short sip[33];
		for(int i=1;i<33;i++)
			scanf("%1d",&sip[i]);
		short ipn[4]={0};
		for(int i=1,j=0;i<33;i+=8,j++)
		{
			short t=128;
			for(int k=i;k<i+8;k++)
			{
				ipn[j]+=(t*sip[k]);
				t/=2;
			}
		}
		cout <<ipn[0] <<"." <<ipn[1] <<"." <<ipn[2] <<"." 
			 <<ipn[3] <<endl;
	}
	return 0;
}
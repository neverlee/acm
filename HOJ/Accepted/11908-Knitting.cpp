// 11908-Knitting.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	short first, row, nc;
	short change[101];
	long total;
	while(cin >>first >>row >>nc)
	{
		if(!first)return 0;
		change[nc]=0;
		for(int i=0;i<nc;i++)
		{
			cin >>change[i];
			change[nc]+=change[i];    //形成的等差
		}
		long total=first;row--;
		long group=0,temp;
		temp=first;
		for(int i=0;i<nc;i++)
		{
			temp+=change[i];
			group+=temp;
		}
		long k=row/nc;
		total+=((group*k)+change[nc]*nc*k*(k-1)/2);
		row%=nc;
		temp=first+k*change[nc];
		for(int i=0;i<row;i++)
		{
			temp+=change[i];
			total+=temp;
		}
		cout <<total <<endl;
	}
}
// 11641-Min Chain.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cmath>
using namespace std;

int q,x,y;

void Extend(int a,int b)
{
	if(b==0)
	{x=1;y=0;q=a;}
	else
	{
		Extend(b,a%b);
		int t=x;
		x=y;
		y=t-a/b*y;
	}
}

int main()
{
	int ncase;cin >>ncase;
	int a,b;
	for(int text=0;text<ncase;text++)
	{
		cin >>a >>b;
		if(a<b)swap(a,b);
		if(a+b==1){cout <<"1" <<endl;continue;}
		if(a==1||b==1){cout <<"2" <<endl;continue;}
		Extend(a,b);
		if(q!=1)
		{cout <<"-1" <<endl;continue;}
		cout <<abs(x)+abs(y)-1 <<endl;
	}
}
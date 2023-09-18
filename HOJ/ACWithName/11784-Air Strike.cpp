// 11784-Air Strike.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

const double PI = 3.141;
short num;
double dis1[1001],dis2[1001];
double power;

inline double x2(double x){return x*x;}

void init()
{
	double tx1,tx2,ty1,ty2;
	cin >>tx1 >>ty1 >>tx2 >>ty2 >>power;
	power/=PI;
	double x,y;
	for(int i=0;i<num;i++)
	{
		cin >>x >>y;
		dis1[i]=x2(x-tx1)+x2(y-ty1);
		dis2[i]=x2(x-tx2)+x2(y-ty2);
	}
}

short Min;

void getanswer()
{
	double power1,power2;
	for(int i=0;i<num;i++)//以第一个为标准
	{
		short havein=num;
		if(dis1[i]<=power)
		{power1=dis1[i];power2=power-dis1[i];}
		else{continue;}
		for(int j=0;j<num;j++)
			if(dis1[j]<=power1||dis2[j]<=power2)
				havein--;
		if(havein<Min)Min=havein;
	}
	//另两种状况
	short havein=num;
	power1=power;power2=0;
	for(int j=0;j<num;j++)
		if(dis1[j]<=power1||dis2[j]<=power2)
			havein--;
	if(havein<Min)Min=havein;
	
	havein=num;
	power1=0;power2=power;
	for(int j=0;j<num;j++)
		if(dis1[j]<=power1||dis2[j]<=power2)
			havein--;
	if(havein<Min)Min=havein;
}

int main()
{
	short kcase=1;
	while(1)
	{
		Min=2000;
		cin >>num;
		if(!num)break;
		init();
		getanswer();
		cout <<kcase <<". " <<Min <<endl;
		kcase++;
	}
	return 0;
}


// 10740-A Simple Problem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

long long level[15]={1,1,2},num;

void SetLevel()
{for(int i=3;(level[i]=level[i-1]*i),i<14;i++);}

void PutResult()
{
	cout <<num <<" = ";
	int wei=0,k;
	while(num>=level[wei])wei++;
	k=num/level[--wei];num%=level[wei];
	if(k>1)cout <<k <<"*" <<wei <<"!";
	else cout <<wei <<"!";
	while(num>0)
	{
		if(num>=level[wei])
		{
			k=num/level[wei];num%=level[wei];
			cout <<" + ";
			if(k>1)cout <<k <<"*";cout <<wei <<"!";
		}
		wei--;
	}
}

int main()
{
	SetLevel();
	int ncase;
	cin >>ncase;
	for(int text=0;text<ncase;text++)
	{
		cin >>num;
		PutResult();
	}
	return 0;
}


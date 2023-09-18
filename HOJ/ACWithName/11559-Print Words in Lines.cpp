// 11559-Print Words in Lines.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
long maxLen, numStr;
long long dpn[10010],strLen[10010];

inline long long X2(long long x)
{return x*x;}

void Dp()
{
	long long temp=strLen[0];
	dpn[0]=X2(maxLen-temp);
	int i;
	for(i=1;((temp+=strLen[i]+1)<=maxLen&&i<numStr);i++)
		dpn[i]=X2(maxLen-temp);
	long long mint; 
	for(;i<numStr;i++)
	{
		temp=strLen[i];
		mint=dpn[i]=X2(maxLen-temp)+dpn[i-1];
		for(int j=i-1;(temp+=(strLen[j]+1))<=maxLen&&j>0;j--)
		{
			mint=X2(maxLen-temp)+dpn[j-1];
			if(mint<dpn[i])dpn[i]=mint;
		}
	}
	cout <<dpn[numStr-1] <<endl;
}

int main()
{
	int textCase;cin >>textCase;
	for(int text=0;text<textCase;text++)
	{
		cin >>maxLen >>numStr;
		for(int i=0;i<numStr;i++)
			cin >>strLen[i];
		Dp();
	}
	return 0;
}
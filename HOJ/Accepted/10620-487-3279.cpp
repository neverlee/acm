// 10620-487-3279.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int num;
short alpha[25]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9};
vector<int> tpn;
void Init()
{
	tpn.reserve(num+1);
	char str[100];
	int k;
	for(int i=0;i<num;i++)
	{
		gets(str);k=0;
		for(int j=0;str[j];j++)
		{
			if(str[j]>='0'&&str[j]<='9')
				k=k*10+str[j]-'0';
			if(str[j]>='A'&&str[j]<'Z'&&str[j]!='Q')
				k=k*10+alpha[str[j]-'A'];
		}
		tpn.push_back(k);
	}
	tpn.push_back(-1);
	sort(tpn.begin(),tpn.end()-1);
}

void PutOut()
{
	int total=1;
	for(int i=0;i<num;i++)
	{
		if(tpn[i]==tpn[i+1])++total;
		else
		{
			if(total>1)
				printf("%03ld-%04ld %ld\n",tpn[i]/10000,tpn[i]%10000,total);
			total=1;
		}
	}
}

int main()
{
	scanf("%ld",&num);getchar();
	Init();
	PutOut();
	return 0;
}
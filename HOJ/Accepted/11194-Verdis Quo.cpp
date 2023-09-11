// 11194-Verdis Quo.cpp : 定义控制台应用程序的入口点。
//
//	freopen("E:\\ACMIn.txt","r",stdin);
//	freopen("E:\\ACMOut.txt","w",stdout);

#include"stdafx.h"

#include<cstdio>
#include<cstring>

int base[24]={0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10};
char str[100];
int num,len,eqr;
int main()
{
	scanf("%ld",&num);getchar();
	for(int i=0;i<num;i++)
	{
		eqr=0;
		gets(str);
		len=strlen(str);
		for(int j=0;j<len;j++)
		{
			if(base[str[j]-'A']>=base[str[j+1]-'A'])
				eqr+=base[str[j]-'A'];
			else
				eqr-=base[str[j]-'A'];
		}
		printf("%ld\n",eqr);
	}
}
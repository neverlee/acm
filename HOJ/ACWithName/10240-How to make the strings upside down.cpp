// 10240-How to make the strings upside down.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdio>
#include<cstring>
char ss[1010],re[1010];
int len;

int main()
{
	int ncase;
	scanf("%ld",&ncase);getchar();
	while(ncase--)
	{
		gets(ss);
		len=strlen(ss);
		re[len]=0;
		for(int i=0,j=len-1;i<len;)
		{
			if(ss[i]<0)
			{
				re[j-1]=ss[i];
				re[j]=ss[i+1];
				i+=2;j-=2;
			}
			else re[j--]=ss[i++];
		}
		puts(re);
	}return 0;
}
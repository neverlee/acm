// 10541-Pesky Palindromes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <cstring>

char str[100];
int len,result;

int main()
{
	while(scanf("%s",str)!=EOF)
	{
		result=0;len=strlen(str);
		for(int i=0;i<len;i++)
			for(int k=0;i-k>=0&&i+k<len;k++)
				if(str[i-k]==str[i+k])++result;
				else break;
		for(int i=0;i<len-1;i++)
			for(int k=0;i-k>=0&&i+k+1<len;k++)
				if(str[i-k]==str[i+k+1])++result;
				else break;
		printf("The string '%s' contains %ld palindromes.\n",str,result);
	}
	return 0;
}

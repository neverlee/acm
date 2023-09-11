// 10639-Hello Kitty.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"

#include<cstdio> 
#include<cstring> 
char str[10000]; 
int times,len; 

int main()
{
	while(scanf("%s",str)!=EOF)
	{
		if(str[0]=='.')return 0;
		scanf("%ld",&times);getchar();
		if(times==0){putchar('\n');continue;}
		len=strlen(str);
		for(int i=0;i<len;i++)
		{
			puts(str+j);
			for(int j=1;j<times;j++)
			printf("%s",str+len);
			for(int j=0;j<i;j++)putchar(str[j]);
			putchar('\n');
		}
	}
	return 0;
}
// 10359-SDEX　Code.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstring>
#include <cstdio>
int main()
{
	char code[27]="01230120022455012623010202";
	char str[100];int len;
	while(scanf("%s",str)!=EOF)
	{
		len=strlen(str);
		for(int i=0;str[i];i++)str[i]=code[str[i]-'A'];
		for(int i=0;i<len-1;i++)
			if(str[i]==str[i+1])str[i]='0';
		for(int i=0;i<len;i++)
			if(str[i]!='0')
				putchar(str[i]);
		putchar('\n');
	}
	return 0;
}
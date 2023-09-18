// 11364-Look and Say.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>

int main()
{
	int ncase;
	scanf("%d",&ncase);getchar();
	char str[1010];
	int count,tc;
	while(scanf("%s",&str)!=EOF)
	{
		tc=str[0];count=1;
		for(int i=1;str[i];i++)
		{
			if(str[i]==tc)count++;
			else
			{
				printf("%d%c",count,tc);
				tc=str[i];count=1;
			}
		}
		printf("%d%c\n",count,tc);
	}
	return 0;
}


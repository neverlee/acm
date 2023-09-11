// 10475-01000001.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <cstring>

int main()
{
	char num1[100],num2[100],*p1,*p2;
	int len1,len2;
	int ncase;scanf("%d",&ncase);getchar();
	for(int text=1;text<=ncase;text++)
	{
		scanf("%s %s",num1+1,num2+1);
		num1[0]=num2[0]=0;
		len1=strlen(num1+1);len2=strlen(num2+1);
		if(len1>=len2){p1=num1+1;p2=num2+1;}
		else{p1=num2+1;p2=num1+1;int t=len1;len1=len2;len2=t;}
		for(int i=0;i<len1;i++)p1[i]-='0';
		for(int i=0;i<len2;i++)p2[i]-='0';
		for(int i=len1-1,j=len2-1;j>=0;i--,j--)
			p1[i]+=p2[j];
		for(int i=len1-1;i>=0;i--)
		{*(p1+i-1)+=(p1[i]/2);p1[i]%=2;}
		printf("%d ",text);
		if(*(p1-1)==1)
		{
			printf("1");
			for(int i=0;i<len1;i++)
				printf("%d",p1[i]);
		}
		else
		{
			int i=0;
			while(!p1[i]&&i<len1)i++;
			if(i==len1){printf("0");}
			else
				for(;i<len1;i++)
					printf("%d",p1[i]);
		}
		printf("\n");
	}
	return 0;
}
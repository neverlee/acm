// 11054-Surprising Strings.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <cstring>
char tp[82],str[82];
char check[676];
int len;
int main()
{
	short temp;bool isS;
	while(gets(tp),tp[0]!='*')
	{
		len=strlen(tp);
		isS=1;
		for(int i=0;i<len;i++)str[i]=tp[i]-'A';
		for(int k=1;k<len;k++)
		{
			memset(check,0,676);
			for(int j=0;j+k<len;j++)
			{
				temp=str[j]*26+str[j+k];
				if(check[temp])
				{isS=0;break;}
				else
					check[temp]=1;
			}
			if(!isS)break;
		}
		if(isS)
			printf("%s is surprising.\n",tp);
		else
			printf("%s is NOT surprising.\n",tp);
	}
	return 0;
}
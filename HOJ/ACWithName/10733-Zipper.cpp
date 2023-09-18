#include "stdafx.h"

#include <cstdio>

int main()
{
	int ncase;scanf("%ld",&ncase);
	char str1[210],str2[210],str3[410];
	int i,j,k;
	for(int text=1;text<=ncase;text++)
	{
		getchar();
		scanf("%s %s %s",str1,str2,str3);
		bool isYes=1;int k1,k2;
		for(i=0,j=0,k=0;str3[k];)
		{
			k1=k2=0;
			while(str1[i+k1]==str3[k+k1]&&str1[i+k1])k1++;
			while(str2[j+k2]==str3[k+k2]&&str2[j+k2])k2++;
			if(k1==0&&k2==0)
			{isYes=0;break;}
			if(k1>k2)
			{i+=k1;k+=k1;}
			else
			{j+=k2;k+=k2;}
		}
		printf("Data set %ld: ",text);
		if(isYes)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
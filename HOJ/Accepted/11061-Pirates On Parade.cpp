// 11061-Pirates On Parade.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdio>
#include<cstdlib>
struct Pirate
{
	char *pname;
	int high;
};
Pirate pirates[1000];
char name[1000][40];
int num=0;
int cmp(const void *a,const void *b)
{return ((Pirate*)a)->high-((Pirate*)b)->high;}
int main()
{
	while(scanf("%s %ld\n",name[num],&pirates[num].high)!=EOF)
	{pirates[num].pname=name[num];num++;}
	qsort(pirates,num,sizeof(Pirate),cmp);
	for(int i=0;i<num-1;)
		if(pirates[i+1].high-pirates[i].high<3)
		{
			printf("%s %s\n",pirates[i].pname,pirates[i+1].pname);
			i+=2;
		}else ++i;
	return 0;
}
// 10614-Vito's family.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <algorithm>
using namespace std;

int ncase,num,rela[510];
int mi,total;

int main()
{
	scanf("%ld",&ncase);
	while(ncase--)
	{
		scanf("%ld",&num);
		for(int i=0;i<num;i++)scanf("%ld",&rela[i]);
		sort(rela,rela+num);
		total=0;
		for(int i=1;i<num;i++)total+=(rela[i]-rela[0]);
		mi=total;
		for(int i=1,j=num-1;i<num-1;i++,j--)
		{
			total+=(i-j)*(rela[i]-rela[i-1]);
			if(total<mi)mi=total;
		}
		printf("%ld\n",mi);
	}
	return 0;
}
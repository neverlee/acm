// 10039-Magician.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include<cstdio>
#include<vector>
using namespace std;
int num,start,k;
int main()
{
	while(scanf("%ld%ld",&num,&start)!=EOF)
	{
		vector<int> v(num);
		for(int i=0;i<num;i++)
			scanf("%ld",&v[i]);
		start%=num;
		for(int i=0;i<10;i++)
		{
			if(start>=num)start=0;
				printf("%ld",v[start++]);
		}
		putchar('\n');
	}
	return 0;
}

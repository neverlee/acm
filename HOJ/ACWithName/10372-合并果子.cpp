// 10372-合并果子.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE=10001;
int num,frult[SIZE];

int main()
{
	int power,tn,k;
	while(scanf("%ld",&num)!=EOF)
	{
		power=0;
		for(int i=0;i<num;i++)
			scanf("%ld",&frult[i]);
		sort(frult,frult+num);
		if(num==1){printf("0\n");continue;}
		for(int i=0;i<num-1;i++)
		{
			tn=frult[i]+frult[i+1];
			power+=tn;
			for(int j=i;j<num;j++)
				printf("%ld ",frult[j]);
			printf("\n");
			for(k=i+2;tn>frult[k]&&k<num;)
			{frult[k-1]=frult[k];k++;}
			frult[k-1]=tn;
		}
		printf("%ld\n",power);
	}
	return 0;
}


#include "stdafx.h"
#include "stdio.h"

int main()
{
	long num,i,k;
	long result[10001];
	for(i=2;(k=i*i)<10001;i++)
		result[i]=k;
	while(scanf("%ld",&num))
	{
		printf("1");
		for(i=2;result[i]<=num;i++)
			printf(" %ld",*(result+i));
		printf("\n");
	}
	return 0;
}
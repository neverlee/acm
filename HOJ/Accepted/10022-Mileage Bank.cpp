// 10022-Mileage Bank.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <cstdio>

int main()
{
	int total=0,length;
	char map[1000],style[10];
	while(scanf("%s",map)!=EOF)
	{
		if(map[0]=='#')return 0;
		if(map[0]=='0')
		{
			printf("%ld\n",total);
			total=0;
			continue;
		}
		scanf(" %s %ld %s",map,&length,style);
		if(style[0]=='F')total+=2*length;
		if(style[0]=='B')total+=1.5*length+length%2;
		if(style[0]=='Y')total+=length>500?length:500;
	}
}

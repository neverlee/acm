// 10315-拼凑春联,10387.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdio>
#include<map>
using namespace std;

char str[8];
int num,have,temp;
map<int,int> spring;
map<int,int>::iterator iter;
pair<int,int> init;
int main()
{
	scanf("%ld",&num);getchar();
	while(num--)
	{
		gets(str);have=1;temp=0;
		for(int i=0;i<7;i++)
			if(str[i]==str[i+1])++have;
			else
			{
				temp=temp*10+have;
				have=1;
			}
		if((iter=spring.find(temp))==spring.end())
		{
			init=make_pair(temp,1);
			spring.insert(init);
		}
		else spring[temp]++;
	}
	temp=0;
	for(iter=spring.begin();iter!=spring.end();iter++)
		temp+=((iter->second*(iter->second-1))/2);
	printf("%ld",temp);
	return 0;
}
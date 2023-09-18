// 10467-幸运儿.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

int main()
{
	int num;
	int person[51],have,len;
	while(cin >>num)
	{
		for(int i=0;i<=num;i++)
			person[i]=i;
		have=len=num;
		while(have>2)
		{
			for(int i=2;i<=len&&have>2;i+=2)
			{
				cout <<person[i] <<" ";
				person[i]=0;have--;
			}
			for(int i=2,j=3;i<=have;i++)
			{
				while(!person[j])j++;
				person[i]=person[j];
				person[j]=0;
			}
			len=have;
		}
		cout <<endl <<person[1] <<" " <<person[2] <<endl;
	}
	return 0;
}
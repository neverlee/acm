// 11794-Minimum Integer sequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;
const long SIZE = 1000;
int main()
{
	char str[2*SIZE+10],result[2*SIZE+10];
	while(cin.getline(str,2*SIZE+5,'\n'))
	{
		char *p1=&str[0],*p2,*p3=&result[0];
		for(p2=p1+1;*p2!=' ';p2++);
		*p2='\0';p2++;
		for(;*p1!='\0'&&*p2!='\0';)
		{
			if(*p1<*p2)
			{*p3=*p1;p1++;}
			else
			{*p3=*p2;p2++;}
			p3++;
		}
		if(*p1!='\0')for(;*p1;*p3++=*p1++);
		if(*p2!='\0')for(;*p2;*p3++=*p2++);
		*p3='\0';
		cout <<result <<endl;
	}
	return 0;
}
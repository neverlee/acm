// 10082-Peter's smokes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

int main()
{
	long n,k,total;
	while(cin >>n >>k)
	{
		total=0;
		for(;n>k;)
		{
			long s;
			s=n/k;
			total+=s*k;
			n=n%k+s;
		}
		total+=n;
		cout <<total <<endl;
	}
	return 0;
}


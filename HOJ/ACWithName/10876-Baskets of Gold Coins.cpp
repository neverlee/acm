// 10876-Baskets of Gold Coins.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	long long a,b,c,d,e;
	while(cin >>a >>b >>c >>d)
	{
		e=(a*(a-1)/2*b-d)/c;
		if(e)
			cout <<e <<endl;
		else
			cout <<a <<endl;
	}
	return 0;
}
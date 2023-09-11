// 11780-Tiles of Tetris, NOT!.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	long a,b;long long re;
	while(1)
	{
		cin >>a >>b;
		if(a==0)break;

		re=a*b;
		if(a==b){cout <<"1" <<endl;continue;}
		cout <<re<<endl;
	}
	return 0;
}
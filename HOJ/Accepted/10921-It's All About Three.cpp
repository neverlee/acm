// 10921-It's All About Three.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int num;
	while(cin >>num)
	{
		num;
		if(num==-1)return 0;
		cout <<num;
		bool flag = 1;
		for(int i=2;i<=num;i++)
		{
			if(num%i==0)
			{
				while(num%i==0)num/=i;
				if(i%10!=3)
				{
					flag=0;break;
				}
			}
		}
		if(flag)cout <<" YES" <<endl;
		else cout <<" NO" <<endl;
	}
}

// 11593-Speed.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	int ncase;cin >>ncase;
	int even,odd,num,temp;
	for(int text=0;text<ncase;text++)
	{
		even=odd=0;cin >>num;
		for(int i=0;i<num;i++)
		{
			cin >>temp;
			if(temp%2)odd++;
			else even++;
		}
		cout <<even <<" even and " <<odd <<" odd." <<endl;
	}
	return 0;
}
// 11060-Dividing the Pirate Hoard.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

int coin,pirate,remain,temp;
int main()
{
	cin >>coin >>pirate;
	remain=coin;
	for(int i=0;i<pirate;i++)
	{
		temp=remain%pirate+remain/pirate;
		remain-=temp;
		cout <<temp;
		if(i!=pirate-1)cout <<" ";
	}
	cout <<endl <<remain <<endl;
}

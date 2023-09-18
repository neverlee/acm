// 10015-Self Numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

inline bool checkself(short num)
{
	for(short i=num-36;i<num;i++)
		if((i+(i/1000)+(i%1000)/100+(i%100)/10+i%10)==num)return false;
	return true;
}

int main()
{
	cout <<1 <<endl <<3 <<endl <<5 <<endl <<7 <<endl <<9 <<endl <<20 <<endl <<31 <<endl <<42 <<endl <<53 <<endl <<64 <<endl;
	for(short i=65;i<9994;i++)
	{
		if(checkself(i))
			cout <<i <<endl;
	}
	system("pause");
	return 0;
}
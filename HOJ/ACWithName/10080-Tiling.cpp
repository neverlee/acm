// 10080-Tiling.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;
const long DIGIT=4;
const long MOD=10000;
const int SIZE=100;
class BigNumber
{
	private:
		long num[SIZE];
		short wei;
	public:
		void sBigNumber();
		void SetNumber(short n);
		void InWei();
		void PutOut();
		friend BigNumber operator*(BigNumber &bnum, long snum);
		friend BigNumber operator+(BigNumber &n1, BigNumber &n2);
};

void BigNumber::sBigNumber()
{
	for(int i=0;i<SIZE;i++)
		num[i]=0;
	wei=0;
}
void BigNumber::SetNumber(short n)
{
	sBigNumber();
	num[0]=n;
}
void BigNumber::InWei()
{
	for(int i=0;i<=wei;i++)
	{
		num[i+1]+=(num[i]/MOD);
		num[i]%=MOD;
	}
	if(num[wei+1])wei++;
}
void BigNumber::PutOut()
{
	printf("%d",num[wei]);
	for(int i=wei-1;i>=0;i--)
		printf("%04d",num[i]);
}


BigNumber operator+(BigNumber &n1, BigNumber &n2)
{
	int max=(n1.wei>n2.wei?n1.wei:n2.wei);
	BigNumber re;re.sBigNumber();
	for(int i=0;i<=max;i++)
		re.num[i]=n1.num[i]+n2.num[i];
	re.wei=max;
	re.InWei();
	return re;
}

int main()
{
	short n;
	BigNumber result[300];
	result[0].SetNumber(1);
	result[1].SetNumber(1);
	result[2].SetNumber(3);
	for(int i=3;i<=250;i++)
	{
		result[i].sBigNumber();
		result[i]=result[i-2]+result[i-1];
		result[i]=result[i]+result[i-2];
	}
	while(cin >>n)
	{
		result[n].PutOut();
		printf("\n");
	}
	return 0;
}


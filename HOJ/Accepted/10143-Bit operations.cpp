// 10143-Bit operations.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cstring>
using namespace std;
const int SIZE = 100;
class BitNum
{
	private:
		short bit[SIZE];
		int wei;
	public:
		BitNum(char str[]);
		void PutOut();
		friend void And(BitNum &one, BitNum &two);
		friend void Or(BitNum &one, BitNum &two);
		friend void Other(BitNum &one, BitNum &two);
};

BitNum::BitNum(char str[])
{
	wei=strlen(str);
	for(int i=wei-1,j=0;i>=0;i--,j++)
	{bit[j]=str[i]-'0';}
}

void BitNum::PutOut()
{
	int i=wei-1;
	while(bit[i]==0&&i>=0)i--;
	if(i<0)cout <<"0";
	else
		for(;i>=0;i--)
			cout <<bit[i];
}

void And(BitNum &one, BitNum &two)
{
	int min=one.wei<two.wei?one.wei:two.wei;
	for(int i=0;i<min;i++)one.bit[i]=one.bit[i]&&two.bit[i];
	one.wei=min;
}

void Or(BitNum &one, BitNum &two)
{
	int min=one.wei<two.wei?one.wei:two.wei;
	for(int i=0;i<min;i++)one.bit[i]=one.bit[i]||two.bit[i];
	if(one.wei<two.wei)
	{
		for(int i=min;i<two.wei;i++)one.bit[i]=two.bit[i];
		one.wei=two.wei;
	}
}

void Other(BitNum &one, BitNum &two)
{
	int min=one.wei<two.wei?one.wei:two.wei;
	for(int i=0;i<min;i++)one.bit[i]=!(one.bit[i]==two.bit[i]);
	if(one.wei<two.wei)
	{
		for(int i=min;i<two.wei;i++)
			one.bit[i]=one.bit[i]!=0;
		one.wei=two.wei;
	}

}

int main()
{
	char str[SIZE],op[10];
	while(cin>>str)
	{
		cin >>op;
		BitNum bn1(str);
		cin >>str;
		BitNum bn2(str);
		switch(op[0])
		{
			case 'X':
				Other(bn1,bn2);break;
			case 'O':
				Or(bn1,bn2);break;
			default:
				And(bn1,bn2);
		}
		bn1.PutOut();
		cout <<endl;
	}
}
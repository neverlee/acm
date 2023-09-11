// 10048-Common permutation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

int main()
{
	char str[1010];
	short cn[2][26],min;
	while(cin >>str)
	{
		for(int i=0;i<2;i++)
			for(int j=0;j<26;j++)
				cn[i][j]=0;
		for(int i=0;str[i];i++)
			cn[0][str[i]-97]++;
		cin >>str;
		for(int i=0;str[i];i++)
			cn[1][str[i]-97]++;
		for(int i=0;i<26;i++)
		{
			//cout <<(char)(97+i) <<" "<<cn[0][i] <<" " <<cn[1][i] <<endl;
			min=(cn[0][i]<cn[1][i]?cn[0][i]:cn[1][i]);
			for(int j=0;j<min;j++)
				cout <<(char)(97+i);
		}
		cout <<endl;
	}
	return 0;
}
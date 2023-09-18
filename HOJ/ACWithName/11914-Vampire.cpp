// 11914-Vampire.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("E:\ACMIn.txt");

long timeLeft[200],timeRight[200];
int main()
{
	int ncase,num,max;
	fin >>ncase;
	for(int i=0;i<ncase;i++)
	{
		fin >>num;
		max=0;
		for(int j=0;j<num;j++)
			fin >>timeLeft[i];
		for(int j=0;j<num;j++)
			fin >>timeRight[i];
		for(int k=0;k<num-1;k++)
		{
			for(int l=k+1;l<num;l++)
			{
				if(timeLeft[l]==(timeLeft[k]+500))
				{
					for(int m=0;m<num-1;m++)
					{
						if(timeRight[m]>timeLeft[l])
						{
							for(int n=m+1;m<num;m++)
							{
								if(timeRight[m]==timeRight[n]-500)
								{
									max++;
									timeLeft[l]=timeLeft[m]=timeRight[m]=timeRight[n]=-1;
								}
							}
						}
					
					}
				}
				if(timeLeft[i]<timeLeft[k]-500)break;
			}
		}
		cout <<max <<endl;
	}
	system("pause");
	return 0;
}
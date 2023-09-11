#include "stdafx.h"
//要通过还得将输入输出改成C的printf和scanf
#include <iostream>
using namespace std;
const long SIZE=50001;
int main()
{
	long num;
	cin >>num;
	long stack[SIZE];
	long pt=0;
	stack[0]=-1;
	long temp;
	for(int i=0;i<num;i++)
	{
		cin >>temp;
		if(temp>stack[pt]){pt++;stack[pt]=temp;}
		else
		{
			long low=0,high=pt,mid;
			while(low<=high)
			{
				mid=(low+high)/2;
				if(temp>stack[mid])low=mid+1;
				else high=mid-1;
			}
			stack[low]=temp;
		}
	}
	cout <<pt <<endl;
	system("pause");
	return 0;
}
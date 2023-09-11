#include "stdafx.h"
#include <iostream>
using namespace std;
short Max(short a,short b)
{return a>b?a:b;}
int main()
{
	short t;
	cin >>t;
	for(int i=0;i<t;i++)
	{
		short high;
		cin >>high;
		short tower[102][102];
		cin >>tower[0][1];
		tower[0][0]=tower[0][2]=0;
		for(int i=1;i<high;i++)
		{
			tower[i][0]=0;
			int j;
			for(j=1;j<=i+1;j++)
			{
				cin >>tower[i][j];
				tower[i][j]+=Max(tower[i-1][j-1],tower[i-1][j]);
			}
			tower[i][j]=0;
		}
		short max=0;
		for(int i=1;i<=high;i++)
			if(tower[high-1][i]>max)max=tower[high-1][i];
		cout <<max <<endl;
	}
	return 0;
}
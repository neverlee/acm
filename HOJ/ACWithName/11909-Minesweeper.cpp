// 11909-Minesweeper.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("E:\ACMIn.txt");
char rect[120][120];
short high,width;
int main()
{
	while(fin >>high >>width)
	{
		if(!high)return 0;
		fin.getline(rect[0]+1,110);
		for(int i=1;i<=high;i++)
		{
			fin.getline(rect[i]+1,110);
			rect[i][0]=rect[i][width+1]=0;
		}
		for(int i=0;i<=width+1;i++)
			rect[0][i]=rect[high+1][i]=0;
		for(int i=1;i<=high;i++)
			for(int j=1;j<=width;j++)
			{
				char n='0';
				if(rect[i][j]=='.')
				{
					if(rect[i-1][j-1]=='*')n++;
					if(rect[i-1][j]=='*')n++;
					if(rect[i-1][j+1]=='*')n++;
					if(rect[i][j-1]=='*')n++;
					if(rect[i][j+1]=='*')n++;
					if(rect[i+1][j-1]=='*')n++;
					if(rect[i+1][j]=='*')n++;
					if(rect[i+1][j+1]=='*')n++;
					rect[i][j]=n;
				}
			}
		for(int i=1;i<=high;i++)
			cout <<rect[i]+1 <<endl;
		system("pause");
	}
}
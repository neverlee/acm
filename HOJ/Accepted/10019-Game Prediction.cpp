// 10019-Game Prediction.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;
char rect[1001];

void Next(int &p,int what)
{do{p--;}while(rect[p]!=what);}

int main()
{
	int people,card,tn,pi,pyou,result,text=0;rect[0]=1;
	while(cin >>people >>card)
	{
		if(people==0)return 0;
		for(int i=1;i<=people*card;i++)
			rect[i]=-1;
		for(int i=0;i<card;i++)
		{
			cin >>tn;
			rect[tn]=1;
		}
		pi=pyou=people*card+1;result=0;
		Next(pi,1);Next(pyou,-1);
		for(int i=0;i<card;i++)
		{
			if(pi>pyou)
			{result++;Next(pi,1);}
			else
			{Next(pi,1);Next(pyou,-1);}
		}
		cout <<"Case " <<++text <<": " <<result <<endl;
	}
}
// 11234-Rock, Paper, or Scissors.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	int ncase,num;char s[10];
	cin >>ncase;
	int w1,w2;
	for(int text=0;text<ncase;text++)
	{
		w1=w2=0;
		cin >>num;
		for(int i=0;i<num;i++)
		{
			cin.getline(s,9);
			while(s[0]==0)cin.getline(s,9);
			if(s[0]==s[2])continue;
			if((s[0]=='R'&&s[2]=='S')||
			   (s[0]=='S'&&s[2]=='P')||
			   (s[0]=='P'&&s[2]=='R'))
			   w1++;
			else w2++;
		}
		if(w1>w2)cout <<"Player 1" <<endl;
		if(w1<w2)cout <<"Player 2" <<endl;
		if(w1==w2)cout <<"TIE" <<endl;
	}
	return 0;
}
// 11451-Palindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int ncase,len;cin >>ncase;
	char str[1010];
	for(int text=0;text<ncase;text++)
	{
		while(cin.getline(str,1005))if(str[0]!=0)break;
		len=strlen(str);
		int i,j;bool flag=1;
		for(i=0,j=len-1;i<=j;i++,j--)
		{
			if(str[i]!=j){flag=0;break;}
		}
		if(flag)cout <<"YES" <<endl;
		else cout <<"NO" <<endl;
	}
}

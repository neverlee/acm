#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int a,b,c,min,re;
	while(cin >>a >>b)
	{
		if(a==-1)return 0;
		c=a+b;
		min=a<b?a:b;
		re=1;
		if(min!=0)
		{
			for(int i=c;i>c-min;i--)
				re*=i;
			for(int i=2;i<=min;i++)
				re/=i;
		}
		if(c==re)
			cout <<a <<"+" <<b <<"=" <<c <<endl;
		else
			cout <<a <<"+" <<b <<"!=" <<c <<endl;
	}
}
// 10155-Making Change.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

int main()
{
	int all,a,b,c,d,remain;
	int need;
	while(cin >>all >>a >>b >>c >>d)
	{
		need=all/25;
		if(d<need){remain=all-d*25;}
		else{remain=all-need*25;d=need;}
		need=remain/10;
		if(c<need){remain-=c*10;}
		else{remain-=need*10;c=need;}
		need=remain/5;
		if(b<need){remain-=b*5;}
		else{remain-=need*5;b=need;}
		need=remain;
		if(a<need){cout <<"Not enough change" <<endl;}
		else{a=need;cout <<a <<" " <<b <<" " <<c <<" " <<d <<endl;}
	}
	return 0;
}
// 10913-Honeycomb Walk.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>

int result[]={0,0,6,12,90,360,2040,10080,54810,290640,1588356,8676360,47977776,266378112,1488801600};
short go[6][2]={-1,-1,-1,1,1,-1,1,1,0,-2,0,2};

short ax,ay;
void GoWalk(short foot,short x,short y)
{
	if(!x&&!y)result[foot]++;
	ax=x<0?-x:x;ay=y<0?-y:y;
	if(ay>ax&&ax+(ay-ax)/2>14-foot)return;
	if(ay<=ax&&ax>14-foot)return;
	for(short i=0;i<6;i++)
		GoWalk(foot+1,x+go[i][0],y+go[i][1]);
}


int main()
{
	freopen("E:\\ACMOut.txt","w",stdout);
	GoWalk(0,0,0);
	for(int i=2;i<15;i++)
		printf("%ld = %ld\n",i,result[i]);
	return 0;
}
// 11472-Amazed.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>
const short SIZE=1002;
const short MAX=32760;
short rect[SIZE][SIZE],high,width;
typedef struct
{short x,y;}Position;
Position start,queue[1000201],go[4]={-1,0,1,0,0,-1,0,1};

void Init()
{
	char tc;getchar();
	for(int i=1;i<=high;i++)
	{
		for(int j=1;j<=width;j++)
		{
			tc=getchar();
			if(tc=='W')
				rect[i][j]=-1;
			else if(tc==' ')
				rect[i][j]=MAX;
			else
			{
				rect[i][j]=0;
				start.x=i;start.y=j;
			}
		}
		getchar();
	}
	for(int i=0;i<=high+1;i++)
		rect[i][0]=rect[i][width+1]=-1;
	for(int i=0;i<=width+1;i++)
		rect[0][i]=rect[high+1][i]=-1;
}

void SetNum()
{
	queue[0]=start;
	int begin=0,end=1;
	short t;
	while(begin<end)
	{
		for(int i=0;i<4;i++)
		{
			t=rect[queue[begin].x+go[i].x][queue[begin].y+go[i].y];
			if(t>rect[queue[begin].x][queue[begin].y]+1)
			{
				queue[end].x=queue[begin].x+go[i].x;
				queue[end].y=queue[begin].y+go[i].y;
				rect[queue[end].x][queue[end].y]=rect[queue[begin].x][queue[begin].y]+1;
				++end;
			}
		}
		++begin;
	}
}

void PutOut()
{
	for(int i=1;i<=high;i++)
	{
		for(int j=1;j<=width;j++)
		{
			switch(rect[i][j])
			{
				case -1:
					printf("WWWWW");break;
				case MAX:
					printf(" inf ");break;
				default:
					printf(" %3d ",rect[i][j]);
			}
		}
		putchar('\n');
	}
	putchar('\n');
}

int main()
{
	while(scanf("%d%d",&high,&width)!=EOF)
	{
		Init();
		SetNum();
		PutOut();
	}
	return 0;
}

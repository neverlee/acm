#include "stdafx.h"
#include <cstdio>
typedef struct
{short x,y;}position;
short ncase;
short height, width;//记录岛的长宽
long islands[1000010];//岛的信息
position pxy[1000010];//排序结果指示
position bcj[1010][1010];//并查集
long numQt, qt[100010], answer[100010];//问题答案
long totalPoint;//记录总的点的个数

void Init()
{
	scanf("%d%d",&height,&width);
	totalPoint=0;
	for(int i=1;i<=height;i++)
		for(int j=1;j<=width;j++)
		{
			scanf("%ld",&islands[totalPoint]);//输入岛信息
			pxy[totalPoint].x=i;
			pxy[totalPoint].y=j;//初始排序岛信息
			totalPoint++;
		}
	scanf("%ld",&numQt);//输入所有问题并初始化排序列
	for(int i=0;i<numQt;i++)
		scanf("%ld",&qt[i]);
	for(int i=0;i<=height+1;i++)
		for(int j=0;j<=width+1;j++)
		{
			bcj[i][j].x=0;
			bcj[i][j].y=0;//初始化并查集
		}
}

void QSort2(int low, int high)//岛高度排序
{
	int s=low,e=high;
	long temp=islands[low];
	position tpt=pxy[low];
	while(s<e)
	{
		while(s<e&&islands[e]<=temp)e--;
		if(s<e){pxy[s]=pxy[e];islands[s]=islands[e];s++;}
		while(s<e&&islands[s]>=temp)s++;
		if(s<e){pxy[e]=pxy[s];islands[e]=islands[s];e--;}
	}
	pxy[s]=tpt;
	islands[s]=temp;
	if(s-low>1)QSort2(low,s-1);
	if(high-s>1)QSort2(s+1,high);
}

position Find(position i)//寻找顶级
{
	if((bcj[i.x][i.y].x==i.x)&&(bcj[i.x][i.y].y==i.y))return i;
	return bcj[i.x][i.y]=Find(bcj[i.x][i.y]);
}

void SetAnswer()
{
	long addI=0;
	long numPart=0;
	short px,py;
	position a,b;
	for(int i=numQt-1;i>=0;i--)
	{
		for(;qt[i]<islands[addI]&&addI<totalPoint;addI++)
		{
			px=pxy[addI].x;py=pxy[addI].y;
			bcj[px][py].x=px;bcj[px][py].y=py;//加入点
			numPart++;//多了一部分

			if(bcj[px-1][py].x&&px-1>0)
			{
				a=Find(bcj[px-1][py]);
				b=Find(bcj[px][py]);
				if(a.x!=b.x||a.y!=b.y)
				{
					numPart--;
					bcj[b.x][b.y]=bcj[a.x][a.y];
				}
			}
			if(bcj[px+1][py].x&&px<height)
			{
				a=Find(bcj[px+1][py]);
				b=Find(bcj[px][py]);
				if(a.x!=b.x||a.y!=b.y)
				{
					numPart--;
					bcj[b.x][b.y]=bcj[a.x][a.y];
				}
			}
			if(bcj[px][py-1].x&&py-1>0)
			{
				a=Find(bcj[px][py-1]);
				b=Find(bcj[px][py]);
				if(a.x!=b.x||a.y!=b.y)
				{
					numPart--;
					bcj[b.x][b.y]=bcj[a.x][a.y];
				}
			}
			if(bcj[px][py+1].x&&py<width)
			{
				a=Find(bcj[px][py+1]);
				b=Find(bcj[px][py]);
				if(a.x!=b.x||a.y!=b.y)
				{
					numPart--;
					bcj[b.x][b.y]=bcj[a.x][a.y];
				}
			}
		}
		answer[i]=numPart;
	}
}

void PutOut()
{
	for(int i=0;i<numQt;i++)
		printf("%ld ",answer[i]);
	printf("\n");
}

int main()
{
	freopen("E:\\ACMIn.txt","r",stdin);
	scanf("%d",&ncase);
	for(int text=0;text<ncase;text++)
	{
		Init();
		QSort2(0,totalPoint-1);
		SetAnswer();
		PutOut();
	}
	return 0;
}

// 11785-Stock Chase.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

typedef struct GNODE
{
	short son;
	struct GNODE *pNext;
}GNode;
short ncom,norder;
GNode pgroup[234];
long needdelete;
void initG()
{
	for(int i=0;i<ncom;i++)
	{
		pgroup[i].pNext=0;
		pgroup[i].son=0;
	}
	short A,B;
	GNode *p1,*p2;
	for(int i=0;i<norder;i++)
	{
		cin >>A >>B;
		p1=&pgroup[B];
		p2=p1->pNext;
		while(p2)
		{p1=p2;p2=p2->pNext;}
		p1->pNext = new GNode;
		p2=p1->pNext;
		p2->son=A;p2->pNext=NULL;
	}
}

void gothrough(short si)
{
	pgroup[si].son=1;//标记访问过
	GNode *p1=&pgroup[si],*p2=p1->pNext;
	while(p2)
	{
		if(pgroup[p2->son].son)//如果下一点已经被访问过
		{
			p2=p2->pNext;
			delete p1->pNext;
			p1->pNext=p2;
			needdelete++;
			continue;
		}
		else
		{
			gothrough(p2->son);//更深层
			p1=p2;p2=p2->pNext;
		}
	}
	pgroup[si].son=0;
}

void destory()
{
	GNode *p1,*p2;
	for(int i=0;i<ncom;i++)
	{
		p1=p2=(pgroup[i].pNext);
		while(p2)
		{
			p2=p2->pNext;
			delete p1;
			p1=p2;
		}
	}
}

int main()
{
	short kcase=1;
	while(1)
	{
		cin >>ncom >>norder;
		if(!ncom)break;
		initG();
		needdelete=0;
		for(int i=0;i<ncom;i++)
			gothrough(i);
		destory();
		cout <<kcase <<". " <<needdelete <<endl;
		kcase++;
	}
	return 0;
}






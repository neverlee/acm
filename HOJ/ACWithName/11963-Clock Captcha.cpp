// 11963-Clock Captcha.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>

char input[7][32];
char bignum[7][60]={
"+---+    ++---++---++   ++---++---++---++---++---+",
"|   |    |    |    ||   ||    |        ||   ||   |",
"|   |    |    |    ||   ||    |        ||   ||   |",
"+   +    ++---++---++---++---++---+    ++---++---+",
"|   |    ||        |    |    ||   |    ||   |    |",
"|   |    ||        |    |    ||   |    ||   |    |",
"+---+    ++---++---+    ++---++---+    ++---++---+"};
int same[4][10];
void SetSame(int n,int pos,int u)
{
	for(int i=0;i<7;i++)
		for(int k=0;k<5;k++)
			if(input[i][pos+k]=='.'||bignum[i][n*5+k]==input[i][pos+k])
				same[u][k]++;
}

void Init()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<10;j++)
			same[i][j]=0;
	for(int i=0;i<3;i++){SetSame(i,0,0);printf("%d ",same[0][i]);}
	printf("\n");
	for(int i=0;i<10;i++){SetSame(i,7,1);printf("%d ",same[1][i]);}
	printf("\n");
	for(int i=0;i<7;i++){SetSame(i,17,2);printf("%d ",same[2][i]);}
	printf("\n");
	for(int i=0;i<10;i++){SetSame(i,24,3);printf("%d ",same[3][i]);}
	printf("\n");

}

int main()
{
	freopen("E:\\ACMIn.txt","r",stdin);
	freopen("E:\\ACMOut.txt","w",stdout);
	char tmp[10];
	while(gets(input[0]),1)
	{
		if(input[0][0]=='e'){printf("end\n");return 0;}
		for(int i=1;i<7;i++)
			gets(input[i]);
		gets(tmp);gets(tmp);
		Init();
	}
}